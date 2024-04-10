#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		if (N % 2)
			cout << 1 << ' ';
		int i;
		for (i = N % 2 + 1; i < N; i += 2)
		{
			cout << i + 1 << ' ' << i << ' ';
		}
		cout << '\n';
	}
}