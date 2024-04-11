#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vector<int> ask(vector<int> w) {
	if(w.empty()) return vector<int>(n, 1<<30);
	cout << w.size() << endl;
	for(auto i : w) cout << i << " "; cout << endl;
	vector<int> ans(n);
	for(auto &i : ans) cin >> i;
	return ans;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vector<int> res(n, 1<<30);
	for(int i = 0; i < 10; i++) {
		vector<int> a, b;
		for(int x = 1; x <= n; x++)
			(((x>>i)&1)?a:b).push_back(x);
		auto ansa = ask(a);
		auto ansb = ask(b);
		for(int x = 1; x <= n; x++) {
			if((x>>i)&1) res[x-1] = min(res[x-1], ansb[x-1]);
			else res[x-1] = min(res[x-1], ansa[x-1]);
		}
	}
	cout << "-1" << endl;
	for(auto &i : res) cout << i << " "; cout << endl;
}