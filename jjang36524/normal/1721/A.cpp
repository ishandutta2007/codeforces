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
		char a, b, c, d;
		cin >> a >> b >> c >> d;
		string t = { a,b,c,d };
		sort(t.begin(), t.end());
		int cx = 0;
		cx += t[0] == t[1];
		cx += t[2] == t[1];
		cx += t[2] == t[3];
		cout << 3 - cx << '\n';
	}
}