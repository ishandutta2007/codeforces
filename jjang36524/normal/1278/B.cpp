#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#define int long long
using namespace std;
int x, y;
signed main()
{
	int N,T;
	cin>> T;

	while (T--)
	{
		cin >> x >> y;
		int i;
		for (i = 0; ; i++)
		{
			int su = i * (i + 1) / 2;
			if (abs(y - x) % 2 == su % 2 && (su >= abs(y - x)))
				break;
		}
		cout << i<<'\n';
	}
}