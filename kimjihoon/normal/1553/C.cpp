#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		string s; cin >> s;
		int c[2] = { 0, 0 }, ans = 10;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '?') c[i & 1] += (int)(s[i] - '0');
			else if (!(i & 1)) c[0]++;
			int t0 = (9 - i) / 2, t1 = (10 - i) / 2;
			if (c[0] > c[1] + t1 || c[1] > c[0] + t0)
				ans = min(ans, i + 1);
		}
		c[0] = 0; c[1] = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '?') c[i & 1] += (int)(s[i] - '0');
			else if (i & 1) c[1]++;
			int t0 = (9 - i) / 2, t1 = (10 - i) / 2;
			if (c[0] > c[1] + t1 || c[1] > c[0] + t0)
				ans = min(ans, i + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}