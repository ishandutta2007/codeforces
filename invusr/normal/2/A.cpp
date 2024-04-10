#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
using namespace std;

const int MaxN = 1005;

int n, score[MaxN], wins = -2000000000;
string name[MaxN];

map<string, int> l, h;

int main()
{
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> name[i] >> score[i];
		l[name[i]] += score[i];
	}
	for (int i = 0; i < n; ++i)
		wins = max(wins, l[name[i]]);

	for (int i = 0; i < n; ++i)
	{
		h[name[i]] += score[i];
		if (l[name[i]] == wins && h[name[i]] >= wins)
		{
			cout << name[i] << endl;
			break;
		}
	}

	return 0;
}