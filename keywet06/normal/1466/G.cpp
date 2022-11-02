#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, A = 26, mod = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += mod;
	return a;
}

int mul(ll a, int b) {
	return (a * b) % mod;
}

int pwr(int x, int e) {
	int res = 1;
	while (e) {
		if (e & 1) {
			res = mul(res, x);
		}
		e /= 2;
		x = mul(x, x);
	}
	return res;
}

string s0, t;
int pre[N][A], p2[N], p2_inv[N];

int solve(string& s, int i, int p, int len, int k);

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	cin >> s0 >> t;
	int l = s0.length();
	p2[0] = p2_inv[0] = 1;
	for (int i = 1; i <= n; ++i) {
		p2[i] = mul(2, p2[i - 1]);
		p2_inv[i] = pwr(p2[i], mod - 2);
	}
	for (int i = 1; i <= n; ++i) {
		for (int c = 0; c < A; ++c) {
			pre[i][c] = pre[i - 1][c];
		}
		pre[i][t[i - 1] - 'a'] = add(pre[i][t[i - 1] - 'a'], p2_inv[i - 1]);
	}
	while (q--) {
		int k; string w;
		cin >> k >> w;
		int m = w.length(), ans = 0;
		for (int p = 0; p <= l; ++p) {
			bool check = true;
			string tmp;
			for (int i = 0, j = p; i < m; ++i, j = (j + 1) % (l + 1)) {
				if (j < l) {
					check &= (w[i] == s0[j]);
				} else {
					tmp += w[i];
				}
			}
			if (!check) {
				continue;
			}
			ans = add(ans, solve(tmp, 0, 0, tmp.length(), k));
		}
		cout << ans << '\n';
	}
}

int solve(string& s, int i, int p, int len, int k) {
	if (i >= len) {
		return p2[k];
	} else if (p == k) {
		return 0;
	}
	int skip = (1 << p);
	int cur = ((len - i + skip - 1) / skip);
	if (cur == 1) {
		return mul(p2[k - 1], sub(pre[k][s[i] - 'a'], pre[p][s[i] - 'a']));
	} else {
		char c = t[p];
		vector<bool> ok(2, true);
		int id = 1;
		for (int j = i; j < len; j += skip) {
			ok[id] = ok[id] & (s[j] == c);
			id ^= 1;
		}
		int ans = 0;
		for (int j = 0; j < 2; ++j) {
			if (ok[j]) {
				ans = add(ans, solve(s, i + j * skip, p + 1, len, k));
			}
		}
		return ans;
	}
}