#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD1 = 1000000007;
// const int MOD2 = 1000000009;
const int MOD = 998244353;

const int B = 43443;

int ns, np, nq;
string s, p, q;
int dp[1000005], z[1000005];
pair<int, int> hs[1000005];
pair<int, int> hp[1000005];
pair<int, int> hq[1000005];
pair<int, int> hpow[1000005];

int lcp_p[1000005];
int lcp_q[1000005];

void hesiraj(const string& s, int ns, pair<int, int>* hs) {
	for (int i = 0; i < ns; i++) {
		hs[i + 1].first = (hs[i].first * 1ll * B + s[i]) % MOD1;
		hs[i + 1].second = (hs[i].second * 1ll * B + s[i]);
	}
}

pair<int, int> hash_range(pair<int, int>* h, int l, int r) {
	int v1 = h[r].first - h[l].first * 1ll * hpow[r - l].first % MOD1;
	int v2 = h[r].second - h[l].second * 1ll * hpow[r - l].second;
	if (v1 < 0) {
		v1 += MOD1;
	}
	return { v1, v2 };
}

void nadji_lcp(pair<int, int>* hs, pair<int, int>* hp, int ns, int np, int* lcp) {
	for (int i = 0; i < ns; i++) {
		int o = 0;
		int l = 1;
		int r = min(ns - i, np);
		
		while (l <= r) {
			int m = (l + r) >> 1;
			if (hash_range(hs, i, i + m) == hash_range(hp, 0, m)) {
				o = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		lcp[i] = o;
	}
}

// vece ili jednako donjoj granici
bool geq(int l, int r) {
	if (r - l < np) {
		return false;
	}
	if (r - l > np) {
		return true;
	}
	int m = lcp_p[l];
	if (m >= r - l) {
		return true;
	}
	return s[l + m] > p[m];
}

// manje ili jednako gornjoj granici
bool leq(int l, int r) {
	if (r - l < nq) {
		return true;
	}
	if (r - l > nq) {
		return false;
	}
	int m = lcp_q[l];
	if (m >= r - l) {
		return true;
	}
	return s[l + m] < q[m];
}

int zl[1000005], zr[1000005];

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s >> p >> q;
	s += '9';
	hpow[0] = { 1, 1 };
	for (int i = 1; i < 1000005; i++) {
		hpow[i].first = hpow[i - 1].first * 1ll * B % MOD1;
		hpow[i].second = hpow[i - 1].second * 1ll * B;
	}

	ns = s.size();
	np = p.size();
	nq = q.size();

	hesiraj(s, ns, hs);
	hesiraj(p, np, hp);
	hesiraj(q, nq, hq);

	// nadji lcp
	nadji_lcp(hs, hp, ns, np, lcp_p);
	nadji_lcp(hs, hq, ns, nq, lcp_q);

	dp[0] = 1;
	for (int i = 0; i < ns; i++) {
		if (i > 0) {
			z[i] += z[i - 1];
			if (z[i] >= MOD) {
				z[i] -= MOD;
			}
			dp[i] += z[i];
			if (dp[i] >= MOD) {
				dp[i] -= MOD;
			}
			zl[i] = zl[i - 1];
			zr[i] = zr[i - 1];
		}

		zl[i] = max(zl[i], i);
		zr[i] = max(zr[i], i);
		
		while (!geq(i, zl[i]) && zl[i] < ns) {
			zl[i]++;
		}
		while (leq(i, zr[i]) && zr[i] < ns) {
			zr[i]++;
		}

		if (s[i] == '0') {
			// moze akko je L = 0 i to samo da uzmes tu nulu
			if (p[0] == '0') {
				z[i + 1] += dp[i];
				if (z[i + 1] >= MOD) {
					z[i + 1] -= MOD;
				}
				z[i + 2] -= dp[i];
				if (z[i + 2] < 0) {
					z[i + 2] += MOD;
				}
			}
			continue;
		}

		z[zl[i]] += dp[i];
		if (z[zl[i]] >= MOD) {
			z[zl[i]] -= MOD;
		}
		z[zr[i]] -= dp[i];
		if (z[zr[i]] < 0) {
			z[zr[i]] += MOD;
		}
	}

	/*
	for (int i = 0; i < ns; i++) {
		cerr << s.substr(0, i) << ": " << dp[i] << '\n';
	}
	*/
	
	cout << dp[ns - 1] << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}