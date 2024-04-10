//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], b[maxn], l[maxn], ans;
map<ll, ll> mp;
vector<ll> vec, g[maxn], lcis;
pair<ll, pll> mx[maxn];
vector<pair<ll, pll> > dp[maxn];
pll p;

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		vec.pb(a[i]);
	}
	cin >> m;
	for(ll i = 0; i < m; i++){
		cin >> b[i];
		vec.pb(b[i]);
	}
	sort(vec.begin(), vec.end());
	for(ll i = 0; i < vec.size(); i++){
		mp[vec[i]] = i;
	}
	for(ll i = 0; i < n; i++){
		a[i] = mp[a[i]];
	}
	for(ll i = 0; i < m; i++){
		b[i] = mp[b[i]];
		g[b[i]].pb(i);
	}
	for(ll i = 0; i < n; i++){
		dp[i].resize(g[a[i]].size());
	}
	fill(l, l + maxn, -1);
	for(ll i = 0; i < n; i++){
		fill(mx, mx + m + 1, Mp(1ll, Mp(-1ll, -1ll)));
		for(ll j = 0; j < a[i]; j++){
			if(l[j] == -1) continue;
			for(ll k = 0; k < g[j].size(); k++){
				mx[g[j][k] + 1] = max(mx[g[j][k] + 1], Mp(dp[l[j]][k].F + 1, Mp(l[j], k)));
			}
		}
		ll t = 0;
		for(ll j = 0; j < m; j++){
			mx[j + 1] = max(mx[j + 1], mx[j]);
			if(b[j] == a[i]){
				dp[i][t] = mx[j];
				if(ans <= dp[i][t].F){
					ans = dp[i][t].F;
					p = Mp(i, t);
				}
				t++;
			}
		}
		l[a[i]] = i;
	}
	cout << ans << '\n';
	if(ans == 0) return 0;
	while(p.F != -1ll){
		lcis.pb(vec[a[p.F]]);
		p = dp[p.F][p.S].S;
	}
	for(ll i = ans; i--;){
		cout << lcis[i] << " ";
	}
	
	return 0;
}