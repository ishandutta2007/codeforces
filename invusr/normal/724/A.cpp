#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
using namespace std;

map<string, int> id;

inline bool ok(int f, int s, int l)
{
	return (f + l) % 7 == s;
}

int main()
{
	id["monday"] = 0;
	id["tuesday"] = 1;
	id["wednesday"] = 2;
	id["thursday"] = 3;
	id["friday"] = 4;
	id["saturday"] = 5;
	id["sunday"] = 6;

	string f, s;
	cin >> f >> s;

	if (ok(id[f], id[s], 28) || ok(id[f], id[s], 30) || ok(id[f], id[s], 31))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}