#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, X, Y;
		cin >> N >> X >> Y;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			X += a;
		}
		if (X % 2 == Y % 2)
		{
			cout << "Alice" << '\n';
		}
		else
			cout << "Bob" << '\n';
	}
}