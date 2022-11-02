#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int p[500009];
bool f[500009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int l = -1, r = -1;
	for (int i = 1; i < n; i++) {
		p[i] = -1;
		if (i <= r) p[i] = min(r - i, p[i - l]);
		while (i + p[i] + 1 < n && s[i + p[i] + 1] == s[p[i] + 1]) p[i]++;
		if (r < i + p[i]) {
			r = i + p[i];
			l = i;
		}
	}
	int t = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		int ti = i + 1;
		for (int r = i + 1; r < k; r += i + 1) {
			int h = ti + p[ti];
			if (h >= t) {
				int tj = t - ti + 1;
				h = t + p[tj] + 1;
			}
			if (r + i <= h) {
				ti = (ti + i + 1) % (t + 1);
				continue;
			}
			int pp = (h + 1) % (t + 1);
			if (s[pp] > s[h - ti + 1]) {
				t = i;
				break;
			}
		}
	}
	int ti = 0;
	for (int i = 0; i < k; i++) {
		cout << s[ti];
		ti = (ti + 1) % (t + 1);
	}
	cout << '\n';
	return 0;	
}