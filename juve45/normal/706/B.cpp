// 706B.cpp : Defines the entry point for the console application.
//

#include<iostream>
using namespace std;
int x[100000];
int main()
{
	int n, v[100000], i, nr, q, m, ans, j = 0, mij, st, dr;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> nr;
		x[nr]++;
	}
	for (i = 0; i <= 100000; i++)
	{
		if (x[i] != 0)
		{
			int t = x[i];
			while (t != 0)
			{
				v[j] = i;
				j++;
				t--;
			}
		}
	}

	cin >> q;
	for (i = 0; i < q; i++)
	{
		cin >> m;
		st = 0;
		dr = n - 1;
		mij = (st + dr+1) / 2;
		if (m >= v[n - 1])
			cout << n << '\n';
		else
			if (m < v[0])
				cout << 0 << '\n';
			else {
				do {
					if (m >= v[mij])
					{
						st = mij ;
						mij = (dr + st+1) / 2;
					}
					else
					{
						dr = mij-1;
						mij = (dr + st+1) / 2;
					}
				} while (st != dr);
				cout << dr+1 << '\n';
			}

	}
	return 0;
}