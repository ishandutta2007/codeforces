//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a[maxn], par[maxn], p1, p2, p;
pll dp[maxn], s1, s2, ans;
vector<ll> vec;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		s1 = s2 = Mp(-inf, inf);
		p1 = p2 = -1;
		ans = Mp(-inf, inf);
		p = -1;
		for(ll i = 0; i < n; i++){
			dp[i] = Mp(0ll, -1ll);
			par[i] = -1;
			if(dp[i] < Mp(s1.F - a[i], s1.S - 1)) dp[i] = Mp(s1.F - a[i], s1.S - 1), par[i] = p1;
			if(dp[i] < Mp(s2.F + a[i], s2.S - 1)) dp[i] = Mp(s2.F + a[i], s2.S - 1), par[i] = p2;
			if(s1 < Mp(dp[i].F + a[i], dp[i].S)) s1 = Mp(dp[i].F + a[i], dp[i].S), p1 = i;
			if(s2 < Mp(dp[i].F - a[i], dp[i].S)) s2 = Mp(dp[i].F - a[i], dp[i].S), p2 = i;
			if(ans < dp[i]) ans = dp[i], p = i;
		}
		vec.clear();
		while(p != -1){
			vec.pb(a[p]);
			p = par[p];
		}
		reverse(vec.begin(), vec.end());
		cout << vec.size() << '\n';
		for(ll i = 0; i < vec.size(); i++){
			cout << vec[i] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}