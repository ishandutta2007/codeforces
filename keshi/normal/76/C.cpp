//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll maxk = 22;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, k, t, f[maxk], c[maxk][maxk], dp[1 << maxk], p, a[maxn], tt, mp[maxk], cc[maxk][maxk], vis[maxk], kk;
string s;
vector<ll> vec;

int main(){
    fast_io;
    
    cin >> n >> k >> t;
    cin >> s;
    for(ll i = 0; i < k; i++){
    	cin >> f[i];
	}
	for(ll i = 0; i < k; i++){
		for(ll j = 0; j < k; j++){
			cin >> cc[i][j];
		}
	}
	for(ll i = 0; i < n; i++){
		a[i] = s[i] - 'A';
		if(!vis[a[i]]) mp[a[i]] = tt++;
		vis[a[i]] = 1;
		a[i] = mp[a[i]];
	}
	for(ll i = 0; i < k; i++){
		if(!vis[i]) continue;
		kk++;
		dp[(1 << mp[i])] += f[i];
		for(ll j = 0; j < k; j++){
			if(!vis[j]) continue;
			c[mp[i]][mp[j]] = cc[i][j];
		}
	}
	for(ll i = 0; i < n; i++){
		ll o = a[i];
		ll x = 0;
		for(ll j = Sz(vec); j--;){
			dp[x] += c[vec[j]][o];
			dp[x | (1 << o)] -= c[vec[j]][o];
			dp[x | (1 << vec[j])] -= c[vec[j]][o];
			dp[x | (1 << vec[j]) | (1 << o)] += c[vec[j]][o];
			x |= (1 << vec[j]);
			if(vec[j] == o) break;
		}
		if(p & (1 << o)) vec.erase(find(all(vec), o));
		vec.pb(o);
		p |= (1 << o);
	}
	for(ll j = 0; j < k; j++){
		for(ll i = 0; i < (1 << kk); i++){
			if((i >> j) & 1) dp[i] += dp[i ^ (1 << j)];
		}
	}
	ll ans = 0;
	for(ll i = 0; i < (1 << kk) - 1; i++){
		if(dp[i] <= t){
			ans++;
		}
	}
	cout << ans;
 
    return 0;
}