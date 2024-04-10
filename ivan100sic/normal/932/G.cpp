#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> to_palin(const string& s) {
	const unsigned mod = 3853518419;
	const unsigned base = 5489143;

	int n = s.size(), h = n/2;
	unsigned ha = 0, hb = 0, hp = 1;
	vector<string> p, q;
	for (int i=0, l=0, r=0; i<h; i++) {
		ha = (ha * 1ull * base + s[i]) % mod;
		hb = (hb + 1ull * s[n-i-1] * hp) % mod;
		hp = (hp * 1ull * base) % mod;
		r++;
		if (ha == hb) {
			p.push_back(s.substr(l, r-l));
			l = r = i+1;
			ha = hb = 0;
			hp = 1;
		}
	}
	q = p;
	sort(q.begin(), q.end());
	q.resize(unique(q.begin(), q.end()) - q.begin());
	vector<int> r(p.size());
	for (int i=0; i<(int)r.size(); i++)
		r[i] = lower_bound(q.begin(), q.end(), p[i]) - q.begin();
	return r;
}

struct triple {
	int i, d, k;
};

vector<vector<triple>> factor(vector<int> s) {
	int n = s.size();
	s.insert(s.begin(), -1);
	vector<vector<triple>> gv(n+1);
	for (int j=1; j<=n; j++) {
		vector<triple> g = gv[j-1], gp, gpp;
		for (auto [i, d, k] : g) {
			if (i > 1 && s[i-1] == s[j])
				gp.push_back({i-1, d, k});
		}
		int r = 1123123123;
		for (auto [i, d, k] : gp) {
			if (i-r != d) {
				gpp.push_back({i, i-r, 1});
				if (k > 0)
					gpp.push_back({i+d, d, k-1});
			} else {
				gpp.push_back({i, d, k});
			}
			r = i + (k-1)*d;
		}
		if (j > 1 && s[j-1] == s[j]) {
			gpp.push_back({j-1, j-1-r, 1});
			r = j-1;
		}
		gpp.push_back({j, j-r, 1});
		g.clear();
		auto [ip, dp, kp] = gpp[0];
		gpp.erase(gpp.begin());
		for (auto [i, d, k] : gpp) {
			if (dp == d) {
				kp += k;
			} else {
				g.push_back({ip, dp, kp});
				ip = i, dp = d, kp = k;
			}
		}
		g.push_back({ip, dp, kp});
		int k = 0;
		for (int i=0; i<(int)g.size(); i++)
			if (g[i].k > 0)
				g[k++] = g[i];
		g.resize(k);
		gv[j] = move(g);
	}
	for (auto& x : gv)
		for (auto& y : x)
			y.i--;
	return gv;
}

string num(int x) {
	if (x < 0)
		return "\xe2\x88\x9e";
	return to_string(x);
}

const unsigned mod = 1'000'000'007;

void ad(unsigned& x, unsigned y) {
	x += y;
	x -= (x >= mod)*mod;
}

ull ht(int x, int y, int z) {
	return 810729873427428ull * x + 84237947198341ull * y
		+ 8673148763467452782ull * z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	auto v = to_palin(s);
	int n = v.size();
	if (n == 0) {
		cout << "0\n";
		return 0;
	}
	// for (int x : v)
	// 	cerr << (char)('a'+x) << ' ';
	auto f = factor(v);
	vector<unsigned> dp(n+1);
	unordered_map<ull, unsigned> store;
	dp[0] = 1;
	for (int j=1; j<=n; j++) {
		for (auto [i, d, k] : f[j]) {
			// cerr << "[" << i << ' ' << d << ' ' << k << "] ";

			int kk = k;
			unsigned v = 0;
			while (kk > 0 && !store.count(ht(i, d, kk))) {
				ad(v, dp[i+(kk-1)*d]);
				kk--;
			}
			if (kk > 0) {
				ad(v, store[ht(i, d, kk)]);
			}
			if (d > 0) {
				store[ht(i, d, k)] = v;
			}
			ad(dp[j], v);
		}
		cerr << '\n';
	}
	cout << dp[n] << '\n';
}