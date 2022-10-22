#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
const int mod = 1e9 + 7;
int pw10[mxn], spw10[mxn];
int f[mxn][2][2], g[mxn][2][2], h[mxn][2][2];

void pre() {
	rep(i, mxn) pw10[i] = i ? 10LL * pw10[i - 1] % mod : 1;
	rep(i, mxn - 1) spw10[i + 1] = (spw10[i] + pw10[i]) % mod;
}

int brute(string s) {
	int n = atoi(s.c_str());
	auto chk = [&] (int x) {
		while (x) {
			if (x % 10 != 4 && x % 10 != 7) {
				return 0;
			}
			x /= 10;
		}
		return 1;
	};
	vector <int> v;
	for (int i = 1; i <= n; ++ i)
		if (chk(i)) v.pb(i);
	int ans = 0;
	rep(i, v.size() - 1) ans += v[i] * v[i + 1];
	return ans;
}

int solve(string s) {
	int n = (int) s.size();
	rep(i, n) s[i] -= '0';
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	memset(h, 0, sizeof(h));
	f[0][0][0] = 1;
	rep(i, n) rep(flag, 2) rep(zero, 2) if (f[i][flag][zero]) {
		for (int c : {0, 4, 7}) {
			if (zero && c == 0) continue;
			if (!flag && c > s[i]) continue;
			int nflag = flag | (c < s[i]), nzero = zero | (c != 0);
			(f[i + 1][nflag][nzero] += f[i][flag][zero]) %= mod;
			(g[i + 1][nflag][nzero] += (10LL * g[i][flag][zero] + 1LL * f[i][flag][zero] * c) % mod) %= mod;
			(h[i + 1][nflag][nzero] += (100LL * h[i][flag][zero] + 20LL * c % mod * g[i][flag][zero] + 1LL * c * c * f[i][flag][zero]) % mod) %= mod;
		}
	}
	int ans = 0;
	for (int i = n - 1; ~i; -- i) {
		rep(flag, 2) if (flag || s[i] == 7) {
			int L = (7LL * spw10[n - i - 1] + 4LL * pw10[n - i - 1]) % mod;
			int R = (7LL * pw10[n - i - 1] + 4LL * spw10[n - i - 1]) % mod;
//			cerr << i << " " << flag << " " << L << " " << R << " ";
//			cerr << f[i][flag][0] + f[i][flag][1] << " ";
//			cerr << g[i][flag][0] + g[i][flag][1] << " ";
//			cerr << h[i][flag][0] + h[i][flag][1] << endl;
			(ans += 1LL * (f[i][flag][0] + f[i][flag][1]) * L % mod * R % mod) %= mod;
			(ans += 1LL * (g[i][flag][0] + g[i][flag][1]) * (L + R) % mod * pw10[n - i] % mod) %= mod;
			(ans += 1LL * (h[i][flag][0] + h[i][flag][1]) * pw10[n - i] % mod * pw10[n - i] % mod) %= mod;
		}
	}
	for (int i = n - 1; i; -- i) {
		int L = 7LL * spw10[n - i] % mod;
		int R = 4LL * spw10[n - i + 1] % mod;
		(ans += 1LL * L * R % mod) %= mod;
	}
//	cerr << ans << endl;
	return ans;
}

int main() {
	pre();
	string L, R;
	cin >> L >> R;
//	cerr << brute(R) << endl << brute(L) << endl;
	cout << (solve(R) + mod - solve(L)) % mod << endl;
	return 0;
}