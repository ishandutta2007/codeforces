#include <iostream>

using namespace std;

const int maxdir=10005;

string dir[maxdir];
int ndir;
string s;

void print()
{
	for (int i=0;i<ndir;i++)
	{
		cout << "/" << dir[i];
	}
	cout << "/" << endl;
}

void parse(int parbegin)
{
	int len=s.length();
	while (parbegin<len)
	{
// 		cout << "parbegin=" << parbegin << " " << s[parbegin] << endl;
		if (s[parbegin]=='.')
		{
			ndir--;
			while (parbegin<len && s[parbegin]!='/') parbegin++;
			parbegin++;
			continue;
		}
		int last=parbegin;
		while (parbegin<len && s[parbegin]!='/') parbegin++;
		dir[ndir]=s.substr(last,parbegin-last);
		ndir++;
		parbegin++;
	}
}

int main()
{
	int n;
	ndir=0;
	cin >> n;
	getline(cin,s);
	for (int i=0;i<n;i++)
	{
		getline(cin,s);
// 		cout << s << endl;
		if (s=="pwd") print();
		else
		{
			int parbegin=2;
			while (s[parbegin]==' ') parbegin++;
			if (s[parbegin]=='/') 
			{
// 				cout << "cd from root" << endl;
				ndir=0;
				parbegin++;
			}
			parse(parbegin);
		}
	}
	return 0;
}