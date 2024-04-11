#pragma optimize("unroll-loops")
#pragma optimize("O3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
struct func {//f = 10k + m/(1 + t*C) + t;
	ld k, m, C;
	void set(ld _k, ld _m, ld _C) {
		k = _k;
		m = _m;
		C = _C;
	}
	inline ld eval(ld t) {
		return 10*k + t + m/(1. + t*C);
	}
	inline ld min() {
		ld l, r, a, b;
		l = 0;
		r = 2e5 + 1234.;
		for(int it = 40; (r-l) > 5e-4 && it--;) {
			a = l + (r-l)/3.;
			b = r - (r-l)/3.;
			if(eval(a) < eval(b))
				r = b;
			else
				l = a;
		}
		return eval(l);
	}
};
vector<ld> cc(1001);

void solve() {
	int n;
	ld t, c;
	cin >> n >> c >> t;
	vector<pair<int, int>> it;
	it.resize(n);
	for(auto &i : it) cin >> i.first >> i.second;
	sort(all(it), greater<pair<int, int>>());
	vector<vector<vector<ld>>> bp(n+2, vector<vector<ld>>(n+2, vector<ld>(10*n+2, 1e18)));
	bp[0][0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int took = 0; took <= i; took++) {
			for(int cst = 0; cst <= 10*i; cst++) {
				bp[i+1][took][cst] = min(bp[i+1][took][cst], bp[i][took][cst]);
				bp[i+1][took+1][cst+it[i].second] = min(bp[i+1][took+1][cst+it[i].second], bp[i][took][cst] + ((ld)it[i].first)/cc[took]);
			}
		}
	}
	func f;
	int ans = 0;
	for(int took = 0; took <= n; took++) {
		for(int cst = 0; cst <= 10*n; cst++) {
			if(10*took + bp[n][took][cst] > 1e10) continue;
			f.set(took, bp[n][took][cst], c);
//			cout << took << " " << cst << " " << c << " " << bp[n][took][cst] << " " << f.min() << " " << t << "\n";
			if(f.min()-t < 1e-4)
				ans = max(ans, cst);
		}
	}
	cout << ans << "\n";
//	cout << " ================ \n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cc[0] = .9;
	for(int i = 1; i <= 101; i++)
		cc[i] = cc[i-1]*.9;
	int t;
	cin >> t;
	while(t--) solve();
}