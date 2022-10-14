#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[maxn], p[maxn], x[maxn], y[maxn], t[maxn];
vector<vector<int>> ops;
vector<int> apply(vector<int> a, vector<int> b) {
	vector<int> res;
	vector<int> nb;
	for(auto &i : b) if(i) nb.push_back(i);
	b = nb;
	if(b.size() == 1) return a;
	ops.push_back(b);
	reverse(all(b));
	int ptr = a.size();
	for(auto &i : b) {
		ptr -= i;
		for(int j = 0; j < i; j++) res.push_back(a[ptr+j]);
	}
	assert(ptr == 0);
	return res;
}
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	for(int type = n&1, i = 1; i <= n; i++, type ^= 1) {
		int pos = -1;
		for(int j = 0; j < n; j++) if(a[j] == i) pos = j;
		pos++;
		if(type) {
			vector<int> O = {pos-1, n - pos + 1 - (i-1)};
			for(int j = 1; j < i; j++) O.push_back({1});
			a = apply(a, O);
		} else {
			vector<int> O;
			for(int j = 1; j < i; j++) O.push_back({1});
			O.push_back(pos - (i-1));
			O.push_back(n - pos);
			a = apply(a, O);	
		}
	}
	cout << ops.size() << '\n';
	for(auto &i : ops) {
		cout << i.size() << " ";
		for(auto j : i) cout << j << " "; cout << '\n';
	}
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
	solve();
}