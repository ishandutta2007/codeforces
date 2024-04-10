#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;
#define int long long
int N, M, T;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N>>M;
		int i;
		int rr = 0;
		for (i = 0; i < N; i++)
		{
			int j;
			for (j = 0; j < M; j++)
			{
				int a;
				cin >> a;
				int r = 4 - (!i) - (i >= N - 1) - (!j) - (j >= M - 1);
				if (a > r)
				{
					if(!rr)
						cout << "NO" << '\n';
					rr = 1;
				}
			}
		}
		if (rr)
			goto R;
		cout << "YES" << '\n';
		for (i = 0; i < N; i++)
		{
			int j;
			for (j = 0; j < M; j++)
			{
				int r = 4 - (!i) - (i >= N - 1) - (!j) - (j >= M - 1);
				cout << r << ' ';
			}
			cout << '\n';
		}
		R:
		int d;
	}
}