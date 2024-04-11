#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
vector<int> f[maxn];
int n, q, last = -1, sz = 0;
oset p;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	for(int t, x; q--;) {
		cin >> t >> x;
		if(t == 1) {
			f[x].push_back(sz);
			p.insert(sz);
			++sz;
		}	
		if(t == 2) {
			for(auto &i : f[x]) p.erase(i);
			f[x].clear();
		}
		if(t == 3) last = max(last, x);
		cout << p.size() - p.order_of_key(last) << '\n';
	}
}