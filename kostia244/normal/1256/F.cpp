//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 1e9 + 7;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n;
	string s,t;
	cin >> n>>s >> t;
	if(n>26) {
		cout << "YES\n";
		return;
	}
	ll ba, bb;
	ba=bb=0;
	oset x, y;
	for(int i = 0; i < n; i++) {
		ba += x.size()-x.order_of_key({s[i], i});
		bb += y.size()-y.order_of_key({t[i], i});
		x.insert({s[i], i});
		y.insert({t[i], i});
	}
	sort(all(s));
	sort(all(t));
	if(s!=t) {
		cout << "NO\n";
		return;
	}
	int ok = 0;
	for(int i = 1; i < n; i++)
		if(s[i]==s[i-1])ok=1;
	if(ok==0&&(ba&1)!=(bb&1)) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	ll t;
	cin >> t;
	while(t--) solve();
}