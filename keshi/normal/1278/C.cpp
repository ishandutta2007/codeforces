//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

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

ll t, n, a[maxn], ps[maxn], ans;

map<ll, ll> mp, pm;
map<ll, bool> v, f;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		mp.clear();
		pm.clear();
		v.clear();
		f.clear();
		cin >> n;
		mp[0] = 0;
		pm[0] = 2 * n + 1;
		for(ll i = 1; i <= 2 * n; i++){
			cin >> a[i];
		}
		ps[0] = 0;
		for(ll i = 1; i <= n; i++){
			if(a[i] == 1) ps[i] = ps[i - 1] + 1;
			else ps[i] = ps[i - 1] - 1;
			mp[ps[i]] = i;
			v[ps[i]] = 1;
		}
		ps[2 * n + 1] = 0;
		for(ll i = 2 * n; i > n; i--){
			if(a[i] == 2) ps[i] = ps[i + 1] + 1;
			else ps[i] = ps[i + 1] - 1;
			pm[ps[i]] = i;
			f[ps[i]] = 1;
		}
		ans = inf;
		v[0] = 1;
		f[0] = 1;
		for(ll i = -n; i <= n; i++){
			if(v[i] && f[i]) ans = min(ans, pm[i] - mp[i] - 1);
		}
		cout << ans << '\n';
	}
	
	return 0;
}