#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		int mi = 1LL << 30;
		int su = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			su += a;
			mi = min(mi, a);
		}
		cout << su - mi * N << '\n';
	}
}