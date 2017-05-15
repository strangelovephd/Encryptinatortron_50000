#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void header();
void encryptinator(short, string, string);
void decryptinator(short, string, string);

int main()
{
	int choice;
	string fileInput;
	string fileOutput;
	short seed;
	do
	{
		system("cls");
		header();
		cout << "Would you like to use the Encryptinator, or the Decryptinator?\n";
		cout << "0. Exit\n";
		cout << "1. Encryptinator\n";
		cout << "2. Decryptinator\n";
		cout << "Choice : ";
		cin >> choice;
		if (choice < 1 || choice > 2)
			continue;
		cout << "Enter original file name : ";
		cin >> fileInput;

		cout << "Enter desired outpuit file name : ";
		cin >> fileOutput;

		do  //do loop to ensure seed is a proper number
		{
			cout << "Enter seed (between 1 and 10) : ";
			cin >> seed;
		} while (seed < 1 || seed > 10);
		
		if (choice == 1)
			encryptinator(seed, fileInput, fileOutput);
		if (choice == 2)
			decryptinator(seed, fileInput, fileOutput);
		
		cout << "Task complete.\n";
		system("pause");

	} while (choice);


	return 0;
}


void encryptinator(short seed, string inputFileName, string outputFileName)
{
	static char fileChar;
	ifstream in(inputFileName.c_str());
	ofstream out(outputFileName.c_str());
	while (in)
	{
		in.get(fileChar);
		out.put(fileChar + seed);
	}

	in.close();
	out.close();
}

void decryptinator(short seed, string inputFileName, string outputFileName)
{

}

void header()
{
	cout << "!!*******************************************************!!\n";
	cout << "!!                Encryptinatortron  5000                !!\n";
	cout << "!!            A bad text file encryption engine          !!\n";
	cout << "!!                                                       !!\n";
	cout << "!!                         by                            !!\n";
	cout << "!!                  Wesley Hendriksen                    !!\n";
	cout << "!!*******************************************************!!\n";
}