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
	ll n, k;
	string s;
	cin >> n >> k >> s;
	ll l = 0;
	string ans, bb;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' && k >= (i - l)) {
			k -= (i - l);
			l++;
			ans.pb(s[i]);
		} else
			bb.pb(s[i]);
	}
	int x = -1;
	for(int i = 0; x==-1&&i<bb.size();i++){
		if(bb[i]=='0')x=i;
	}
	while(x!=-1&&k&&x) {
		swap(bb[x], bb[x-1]);
		k--;
		x--;
	}
	cout << ans+bb << "\n";
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}