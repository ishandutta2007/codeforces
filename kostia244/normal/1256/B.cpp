//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
//using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 1e9 + 7;
//using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	vi a;
	int n;
	cin >> n;
	a.resize(n);for(auto &i : a) cin >> i;
	int l = 0;
	while(l+1<n) {
		int t= l;
		for(int i = l; i < n; i++) {
			if(a[t]>a[i])t=i;
		}
		for(int i = t-1; i >= l; i--)
			swap(a[i], a[i+1]);
		l = t + (t==l);
	}
	for(auto i : a) cout << i << " ";
	cout << '\n';
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}