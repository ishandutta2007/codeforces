#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, k; cin >> n >> k, --k;
	vector<pair<int, int>> lines(k);
	for (int c = 0; c < k; ++c) lines[c] = {n - 1, c};
	vector<vector<bool>> f(n, vector<bool>(n)), t(f);
	for (int r = 0; r < n; ++r) {
		string s; cin >> s;
		for (int c = 0; c < n; ++c) t[r][c] = s[c] == '1';
	}
	auto paint = [&] (int r1, int c1, int r2, int c2) {
		if (r1 > r2 || c1 > c2) swap(r1, r2), swap(c1, c2);
		for (int r = r1; r <= r2; ++r)
			for (int c = c1; c <= c2; ++c)
				f[r][c] = 1;
	};
	for (int r = n - 1; r >= 0; --r) {
		int i = k - 1;
		for (int c = n - 1; c >= 0; --c) {
			if (!t[r][c]) {
				while (i >= 0 && lines[i].second > c) --i;
				if (i == -1) {
					cout << "NO\n";
					return;
				}
				paint(r, lines[i].second, lines[i].first, lines[i].second);
				paint(r, c, r, lines[i].second);
				int oc = lines[i].second;	
				lines[i] = {r, c};
				c = oc;
			}
		}
		if (lines.size() > r) {
			paint(r, lines.back().second, lines.back().first, lines.back().second);
			paint(r, n - 1, r, lines.back().second);
			lines.pop_back();
		}
	}
	cout << "YES\n";
	for (auto& r : f) {
		for (int rr : r) cout << rr;
		cout << '\n';
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}