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
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, h, ans, c[maxn], dp[maxn], par[maxn];

bool f[maxn];

vector<ll> v[maxn], an;

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> h;
		f[h] = 1;
	}
	
	for(ll i = 1; i < m; i++){
		if(!f[i]){
			c[__gcd(i, m)]++;
			v[__gcd(i, m)].pb(i);
		}
	}
	
	h = 1;
	
	for(ll i = 1; i < m; i++){
		for(ll j = 1; j * j <= i; j++){
			if(i % j == 0){
				if(dp[i] < dp[j]) dp[i] = max(dp[i], dp[j]), par[i] = j;
				if(dp[i] < dp[i / j]) dp[i] = max(dp[i], dp[i / j]), par[i] = i / j;
			}
		}
		dp[i] += c[i];
		if(ans < dp[i]) ans = dp[i], h = i;
	}
	
	while(h){
		for(ll i = 0; i < v[h].size(); i++){
			an.pb(v[h][i]);
		}
		h = par[h];
	}
	
	reverse(an.begin(), an.end());
	
	ll x = 0, y = 0;
	
	if(!f[0]) ans++, an.pb(0);
	
	ll l = 1;
	
	cout << ans << '\n';
	
	for(ll i = 0; i < ans; i++){
		h = __gcd(l, m);
		x = 0;
		y = 0;
		gcd(l / h, m / h, x, y);
		cout << (((an[i] / h) * x) % m + m) % m << " ";
		l = an[i];
	}
	
	return 0;
}