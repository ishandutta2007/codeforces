#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int N, M,T;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		M--;
		while (M--)
		{
			int i = 1;
			int mi = 9, ma = 0;
			while (i <= N)
			{
				int r = N / i % 10;
				mi = min(mi, r);
				ma = max(ma, r);
				i *= 10;
			}
			if (mi == 0)
				break;
			else
				N += mi * ma;
		}
		cout << N<<'\n';
	}
}