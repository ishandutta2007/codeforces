#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define int long long
using namespace std;
string x, y;
signed main()
{
	int N,T;
	cin>> T;

	while (T--)
	{
		cin >> x >> y;
		int i, j, k;
		int sx = x.size();
		int sy = y.size();
		int arr[26] = { 0, };
		for (i = 0; i < sx; i++)
		{
			arr[x[i] - 'a']++;
		}
		int p = 1;
		for (i = 0; i <= sy-sx; i++)
		{
			int arrr[26] = { 0, };
			for (j = 0; j < sx; j++)
			{
				arrr[y[i+j] - 'a']++;
			}
			int ay = 1;
			for (j = 0;  j< 26; j++)
			{
				if (arr[j] != arrr[j])
					ay = 0;
			}
			if (ay == 1)
			{
				cout << "YES" << '\n';
				p = 0;
				break;
			}
		}
		if (p)
			cout << "NO" << '\n';
	}
}