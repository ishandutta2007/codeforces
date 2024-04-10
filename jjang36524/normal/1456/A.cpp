#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#define int long long
using namespace std;
int tim[200100];
signed main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(tim, 0, sizeof(tim));
		int N, a, b;
		cin >> N >> a >> b;
		a--;
		string s;
		cin >> s;
		int x, y;
		cin >> x >> y;
		int i;
		for (i = N - 1; i >= 0; i--)
		{
			tim[i] = tim[i + b] + (s[i] == '0') * x;
		}
		int ans = 1LL << 50;
		for (i = a; i < N; i++)
		{
			ans = min(ans, tim[i] + (i - a) * y);
		}
		cout << ans << '\n';
	}
}