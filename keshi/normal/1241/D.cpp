#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, m, a[maxn], r[maxn], l[maxn], dp[maxn], ans;

vector<ll> v;

bool vis[maxn];

bool check(ll i, ll j){
	return r[v[i]] < l[v[j]];
}

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n;
		fill(vis, vis + n + 10, 0);
		fill(dp, dp + n + 10, inf);
		v.clear();
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			if(!vis[a[i]]){
				v.pb(a[i]);
				vis[a[i]] = 1;
				l[a[i]] = i;
			}
			r[a[i]] = i;
		}
		sort(v.begin(), v.end());
		dp[0] = 1;
		for(ll i = 1; i < v.size(); i++){
			if(check(i - 1, i)){
				dp[i] = dp[i - 1] + 1;
			}
			else{
				dp[i] = 1;
			}
		}
		ans = 0;
		for(ll i = 0; i < v.size(); i++){
			ans = max(ans, dp[i]);
		}
		cout << v.size() - ans << endl;
	}
	
	return 0;
}