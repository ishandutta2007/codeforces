#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define se second
#define fi first
#define pb push_back
#define mp make_pair

int type (string s)
{
	int n = s.length();
	if (n >= 4 && s.substr(n-4, 4) == "lios")
		return 0;
	else if (n >= 5 && s.substr(n-5, 5) == "liala")
		return 1;
	else if (n >= 3 && s.substr(n-3, 3) == "etr")
		return 2;
	else if (n >= 4 && s.substr(n-4, 4) == "etra")
		return 3;
	else if (n >= 6 && s.substr(n-6, 6) == "initis")
		return 4;
	else if (n >= 6 && s.substr(n-6, 6) == "inites")
		return 5;
	else
		return -1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	vector<int> a;
	bool be1 = false, be2 = false;
	string s;
	
	while (!cin.eof())
	{
		cin >> s;
		a.pb(type(s));
		if (a.back() == -1)
		{
			cout << "NO";
			return 0;
		}
		if (a.back() % 2 == 0)	
			be1 = true;
		else
			be2 = true;
	}
	
	if (!a.empty())
		a.pop_back();
	if (a.size() == 1)
	{
		cout << "YES";
		return 0;
	}
	else
	{
		if ((be1 && be2) || count(a.begin(), a.end(), 2 + be2) != 1)
		{
			cout << "NO";
			return 0;
		}
		forn(i, a.size() - 1)
			if (a[i] > a[i+1])
			{
				cout << "NO";
				return 0;
			}
	}
	cout << "YES";
	
	return 0;
}