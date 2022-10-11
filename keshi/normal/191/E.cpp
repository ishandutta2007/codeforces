//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a[maxn], ps[maxn];

ll cal(ll x){
	ll s = 0;
	Tree<pll> q;
	q.insert({0, 0});
	for(ll i = 1; i <= n; i++){
		s += q.order_of_key({ps[i] - x, i});
		q.insert({ps[i], i});
	}
	return s;
}

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	
	ll l = -2e14, r = 2e14, mid;
	
	while(r - l > 1){
		mid = (l + r) / 2;
		if(cal(mid) >= k) l = mid;
		else r = mid;
	}
	
	cout << l;
	
	return 0;
}