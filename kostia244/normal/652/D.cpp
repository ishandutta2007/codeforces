//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 2020, mod = 998244353;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<int, pi> cl;
	int n, l, r;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		cl[r] = {l, i};
	}
	vi ans(n);
	oset fuck;
	for(auto i : cl) {
		ans[i.second.second] = fuck.size() - fuck.order_of_key(i.second.first);
		fuck.insert(i.second.first);
	}
	for(auto i : ans) cout << i << '\n';
}