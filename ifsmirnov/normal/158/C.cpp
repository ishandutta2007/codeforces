#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back

int n;
vector<string> cur;

void pwd()
{
	cout << "/";
	forn(i, cur.size())
		cout << cur[i] << "/";
	cout << endl;
}
void cd (string s)
{
	if (s == "") return;
	if (s[0] == '/')
	{
		cur.clear();
		cd(s.substr(1));
	}
	else
	{
		int pos = s.find("/");
		if (pos == (int)string::npos)
		{
			if (s == "..")
				cur.pop_back();
			else
				cur.pb(s);
		}
		else
		{
			cur.pb(s.substr(0, pos));
			if (cur.back() == "..")
				cur.pop_back(), cur.pop_back();
			cd(s.substr(pos+1));
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	forn(i, n)
	{
		string s;
		cin >> s;
		if (s == "cd")
		{
			cin >> s;
			cd(s);
		}
		else
			pwd();
	}
	
	return 0;
}