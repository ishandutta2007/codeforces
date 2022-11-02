#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int c = 0, rc = 0, ans = 0;
		bool f = false;
		v.clear();
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'W') {
				if (f && rc) {
					v.push_back(rc);
					c -= rc;
				}
				f = true; rc = 0;
				if (i > 0 && s[i - 1] == 'W') ans += 2;
				else ans++;
			}
			else {
				c++; rc++;
			}
		}
		if (!f) {
			cout << max(0, k * 2 - 1) << '\n';
			continue;
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			if (k >= v[i]) {
				k -= v[i];
				ans += 2 * v[i] + 1;
			}
			else {
				ans += 2 * k;
				k = 0;
				break;
			}
		}
		ans += min(k, c) * 2;
		cout << ans << '\n';
	}
	return 0;
}