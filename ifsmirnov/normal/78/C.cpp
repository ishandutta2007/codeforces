#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)

int n, m, k;

map<int, bool> res;

bool get(int);

int main()
{
	cin >> n >> m >> k;
	if (get(m) && (n%2))
		cout << "Timur";
	else
		cout << "Marsel";

	return 0;	
};
bool get (int n)
{
	if (res.count(n))
		return res[n];
	for (int i = 1; i * i <= n; i++)
	{       
		if (n%i)
			continue;
		{
			int a = i, b = n/i;
			if (a >= k && b > 1 && (get(a) == 0 || (b%2) == 0))
			{
				res[n] = 1;
				return true;
			}
		}
		{
			int b = i, a = n/i;
			if (a >= k && b > 1 && (get(a) == 0 || (b%2) == 0))
			{
				res[n] = 1;
				return true;
			}
		}
	}
	res[n] = 0;
	return false;
};