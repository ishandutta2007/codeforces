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
		int n; cin >> n;
		string s; cin >> s;
		if (s[0] == '9') {
			string ans = "";
			int r = 0;
			for (int i = n - 1; i >= 0; i--) {
				int t = (int)(s[i] - '0');
				if (t + r <= 1) {
					ans += (char)('0' + (1 - t - r));
					r = 0;
				}
				else {
					ans += (char)('0' + (11 - t - r));
					r = 1;
				}
			}
			reverse(ans.begin(), ans.end());
			cout << ans << '\n';
		}
		else {
			string ans = "";
			for (int i = 0; i < n; i++)
				ans += (char)('0' + (int)('9' - s[i]));
			cout << ans << '\n';
		}
	}
	return 0;
}