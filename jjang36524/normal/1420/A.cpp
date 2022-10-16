#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int N;
int T;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int bef = (1 << 30);
		int i;
		int su = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (bef <= a)
				su = 1;
			bef = a;
		}
		cout << (su ? "YES" : "NO") << '\n';
	}
}