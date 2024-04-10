//In the name of GOD
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll maxn = 1e6 + 100;
const ll maxm = 1e4;
const ll lg = 40;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
 
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second
 
mt19937 rng(time(0));
 
ll n, a[maxn], dp[maxn], b[maxm][lg], c[maxm][lg], d[maxm], x, t, l, r, mid, ans, s;
 
pll g[maxm];
 
int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll k = 0; k < 15; k++){
		x = a[rng() % n];
		s = 0;
		for(ll i = 2; i * i <= x; i++){
			if(x % i == 0){
				g[s] = {i, 0};
				while(x % i == 0) x /= i, g[s].S++;
				s++;
			}
		}
		if(x != 1) g[s++] = {x, 1};
		for(ll i = 0; i < s; i++){
			b[i][0] = 1;
			for(ll j = 1; j <= g[i].S; j++){
				b[i][j] = b[i][j - 1] * g[i].F;
			}
		}
		for(ll i = 0; i < n; i++){
			t = 0;
			for(ll j = 0; j < s; j++){
				l = 0, r = g[j].S + 1;
				while(r - l > 1){
					mid = (l + r) / 2;
					if(a[i] % b[j][mid] == 0) l = mid;
					else r = mid;
				}
				t = t * (g[j].S + 1) + l;
			}
			dp[t]++;
		}
		t = 1;
		for(ll i = s; i--;){
			d[s - i - 1] = t;
		    t *= g[i].S + 1;
		}
		for(ll i = 0; i < t; i++){
			x = i;
			for(ll j = s; j--;){
				c[i][s - j - 1] = x % (g[j].S + 1);
				x /= g[j].S + 1;
			}
		}
		for(ll j = 1; j <= s; j++){
			for(ll i = t; i--;){
				if(c[i][j - 1] != g[s - j].S) dp[i] += dp[i + d[j - 1]];
			}
		}
		for(ll i = 0; i < t; i++){
			x = 1;
			if(dp[i] * 2 >= n){
				for(ll j = 0; j < s; j++){
					x *= b[s - 1 - j][c[i][j]];
				}
			}
			ans = max(ans, x);
			dp[i] = 0;
		}
	}
	
	cout << ans;
	
	return 0;
}