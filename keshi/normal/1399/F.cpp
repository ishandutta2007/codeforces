//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, m, l[maxn], r[maxn], dp[maxn], ps[maxn];
bool vis[maxn];
vector<ll> g[maxn], vec;
pll p[maxn];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		vec.clear();
		for(ll i = 0; i < n; i++){
			cin >> l[i] >> r[i];
			if(!vis[l[i]]) vec.pb(l[i]);
			vis[l[i]] = 1;
			if(!vis[r[i]]) vec.pb(r[i]);
			vis[r[i]] = 1;
		}
		vec.pb(-inf);
		vec.pb(inf);
		sort(vec.begin(), vec.end());
		for(ll i = 0; i < n; i++){
			vis[l[i]] = vis[r[i]] = 0;
			l[i] = lower_bound(vec.begin(), vec.end(), l[i]) - vec.begin();
			r[i] = lower_bound(vec.begin(), vec.end(), r[i]) - vec.begin();
			g[l[i]].pb(i);
			p[i] = Mp(r[i] - l[i], i);
		}
		l[n] = 0;
		r[n] = vec.size() - 1;
		p[n] = Mp(vec.size(), n);
		sort(p, p + n + 1);
		for(ll o = 0; o <= n; o++){
			ll i = p[o].S;
			ll v;
			ps[r[i] + 1] = 0;
			for(ll j = r[i]; j >= l[i]; j--){
				ps[j] = ps[j + 1];
				for(ll k = 0; k < g[j].size(); k++){
					v = g[j][k];
					if(r[v] <= r[i]) ps[j] = max(ps[j], dp[v] + ps[r[v] + 1]);
				}
			}
			dp[i] = ps[l[i]] + 1;
		}
		cout << dp[n] - 1 << '\n';
		for(ll i = 0; i <= n; i++){
			g[l[i]].clear();
			dp[i] = 0;
		}
	}
	
	return 0;
}