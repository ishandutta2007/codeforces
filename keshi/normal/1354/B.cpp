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

ll t, ans, x;
string s;
vector<ll> a[3];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> s;
		a[0].clear();
		a[1].clear();
		a[2].clear();
		for(ll i = 0; i < s.size(); i++){
			a[s[i] - '1'].pb(i);
		}
		a[0].pb(s.size());
		a[1].pb(s.size());
		a[2].pb(s.size());
		ans = inf;
		for(ll i = 0; i < s.size(); i++){
			x = max(*lower_bound(a[0].begin(), a[0].end(), i), max(*lower_bound(a[1].begin(), a[1].end(), i), *lower_bound(a[2].begin(), a[2].end(), i)));
			if(x < s.size()) ans = min(ans, x - i + 1);
		}
		if(ans == inf) ans = 0;
		cout << ans << '\n';
	}
	
	return 0;
}