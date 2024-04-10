#include <iostream>
#include <string>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)

int n;

int main()
{
	cin >> n;
	if (n == 1)
		cout << "a\na\nb\nb\n";
	else if (n == 2)
		cout << "aa\nbb\naa\nbb\n";
	else
	{
		//1 2
		string s1="", s2="";
		for (int i = 0; i < (n&(~1)); i++)
			if (i%4>1) s1 += 'a';
			else s1 += 'b';
		cout << s1;
		if (n%2) cout << "z";
		cout << endl;
		forn(i, s1.size()) s1[i] += 2;
		cout << s1;
		if (n%2) cout << "z";
		cout << endl;
		if (n%2 == 0) s1.resize(s1.length()-2);
		forn(i, s1.size()) s1[i] += 2;
		cout << "z" << s1;
		if (n%2==0) cout << "z";
		cout << endl;
		forn(i, s1.size()) s1[i] += 2;
		cout << "z" << s1;
		if (n%2==0) cout << "z";
	}
};