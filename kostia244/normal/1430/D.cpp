#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1e3 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;string s;
		cin >> n >> s;
		vector<int> B;
		s += "$";
		int c = 0, bid = 0;
		char p = s[0];
		for(auto &i : s) {
			if(p == i) c++;
			else {
				if(c)
				B.push_back(c);
				c = 1;
			}
			p = i;
		}
		set<array<int, 2>> x, y;
		for(int i = 0; i < B.size(); i++) {
			x.insert({i, B[i]});
			if(B[i] > 1) y.insert({i, B[i]});
		}
		int res = 0;
		while(!x.empty() || !y.empty()) {
			res++;
			if(!y.empty()) {
				auto v = *y.begin();y.erase(y.begin());
				if(--v[1] > 1) y.insert(v);
			} else {
				x.erase(x.begin());
			}
			if(x.size()) {
				auto t = *x.begin();
				if(t[1] > 1) {
					auto F = y.lower_bound({t[0], 0});
					if(F != y.end() && F->at(0) == t[0]) y.erase(F);
				}
				x.erase(x.begin());
			}
		}
		cout << res << '\n';
	}
}