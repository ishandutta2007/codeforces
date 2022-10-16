#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define int long long
using namespace std;
int T, a, b, c, d, e, f;
int arr[1000100];
int p[1000100][3];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> a>>b;
		int i;
		int s = 0;
		for (i = 0; i < a; i++)
		{
			char g;
			cin >> g;
			arr[i] = g-'0';
			s += arr[i];
		}
		c = a * 2;
		for (i = 0; i < b; i++)
		{
			int j;
			int pp = 0;
			for (j = i; j < a; j += b)
			{
				pp += arr[j];
				if (j == i)
				{
					p[j][0] = arr[j];
					p[j][1] = !arr[j];
				}
				else
				{
					p[j][0] = p[j - b][0] + arr[j];
					p[j][1] = min(p[j - b][0], p[j - b][1]) + !arr[j];
					p[j][2] = min(min(p[j - b][0], p[j - b][1]), p[j - b][2]) + arr[j];
				}
			}
			int rans = s - pp+min(p[j-b][2],p[j-b][1]);
			c = min(c, rans);
		}
		cout << c<<'\n';
	}
}