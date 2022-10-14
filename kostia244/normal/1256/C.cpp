//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
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
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	ll n, m, d;
	cin >> n >> m >> d;
	vi a;
	a.resize(m);
	ll sm = 0;
	for(auto &i : a) cin >> i, sm += i;
	int st = n;
	vi b(n, 0);
	for(int i = m; i--;) {
		ll t = max(sm-1, st-d);
		for(int l = t, j = a[i]; j--; l--)
			b[l] = i+1;
		st = t-a[i]+1;
		sm -= a[i];
	}
	if(st>=d)return cout << "NO", 0;
	cout << "YES\n";
	for(int i = 0; i < n; i++) cout << b[i] << " ";
}