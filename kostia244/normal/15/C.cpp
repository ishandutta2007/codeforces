//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e2 + 5;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ll get(ll i, ll mx = 59) {
	if(i<2) return i;
	if(i==2) return 3;
	if(i==3) return 0;
	for(ll z = mx; z>=0; z--) {
		if((i>>z)&1) {
			ll ans = get(i^(1ll<<z), z-1);
			if(i%2==0) ans ^= 1ll<<z;
			return ans;
		}
	}
}
ll t, ans = 0, x, m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--) {
		cin >> x >> m, x--;
		ans ^= get(x+m);
		ans ^= get(x);
	}
	cout << (ans?"tolik":"bolik");
}