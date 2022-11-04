#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const int mod = 998244353;
const int M = 17;

ll mpow(ll a,ll b){return b?(b&1?a:1)*mpow(a*a%mod,b/2)%mod:1;}

void ProGamerMove() {
	int n; cin >> n;
	string s; cin >> s;
	int q; cin >> q;
	int tq = count(s.begin(), s.end(), '?');

	vector<vector<int>> f(1 << M, vector<int>(M + 1));
	for (int i = 0; i < 2 * n - 1; ++i) {
		vector<int> strings(M + 1, 1);
		int mask = 0, qs = 0;
		for (int l = i / 2, r = (i + 1) / 2; l >= 0 && r < n; --l, ++r) {
			if ((s[l] == '?') ^ (s[r] == '?')) {
				mask |= s[l] != '?' ? 1 << (s[l] - 'a') : 0;
				mask |= s[r] != '?' ? 1 << (s[r] - 'a') : 0;
			}
			qs += s[l] == '?';
			qs += (l != r && s[r] == '?');
			if (s[l] != '?' && s[r] != '?' && s[l] != s[r])
				break;
			if (s[l] == '?' && s[r] == '?')
				for (int j = 1; j <= M; ++j)
					strings[j] = (ll)strings[j] * j % mod;
			for (int j = 1; j <= M; ++j)
				f[mask][j] = (f[mask][j] + strings[j] * (ll)mpow(j, tq - qs)) % mod;
		}
	}
	vector<int> res(1 << M);
	for (int m = 0; m < 1 << M; ++m) {
		for (int m2 = m; m2 >= 0; m2 = (m2 - 1) & m) {
			res[m] = (res[m] + f[m2][__builtin_popcount(m)]) % mod;
			if (m2 == 0) break;
		}
	}
	while (q--) {
		string x; cin >> x;
		int mask = 0;
		for (char c : x) mask |= 1 << (c - 'a');
		cout << res[mask] << '\n';
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	// cin >> tc;
	while (tc--) ProGamerMove();
}