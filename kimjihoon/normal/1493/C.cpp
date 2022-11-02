#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, k, p[29], r;

void rp(int i, int t)
{
	if (t == 1) {
		p[i] = (p[i] + 1) % k;
		if (p[i] == 1) r += k - 1;
		else r--;
	}
	else {
		p[i] = (p[i] - 1 + k) % k;
		if (p[i] == 0) r -= k - 1;
		else r++;
	}
}

void ps()
{
	cin >> n >> k;
	string s; cin >> s;
	if (n % k != 0) {
		cout << -1 << '\n';
		return;
	}
	if (k == 1) {
		cout << s << '\n';
		return;
	}
	for (int i = 0; i < 26; i++)
		p[i] = 0;
	r = 0;
	for (int i = 0; i < n; i++) {
		int t = s[i] - 'a';
		rp(t, 1);
	}
	if (r == 0) {
		cout << s << '\n';
		return;
	}
	for (int i = n - 1; i >= 0; i--) {
		int t = s[i] - 'a';
		rp(t, -1);
		for (int j = t + 1; j < 26; j++) {
			rp(j, 1);
			if (r <= n - 1 - i) {
				string ans = "";
				for (int si = 0; si < i; si++)
					ans += s[si];
				ans += (char)(j + 'a');
				int pi = 0;
				while (n - (int)ans.size() - r >= k) {
					for (int si = 0; si < k; si++)
						ans += 'a';
				}
				for (int pi = 0; pi < 26; pi++) {
					while (p[pi] != 0) {
						ans += (char)(pi + 'a');
						p[pi] = (p[pi] + 1) % k;
					}
				}
				cout << ans << '\n';
				return;
			}
			rp(j, -1);
		}
	}
	cout << -1 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		ps();
	}
	return 0;
}