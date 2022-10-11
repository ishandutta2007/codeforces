//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll lg = 19;
const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, x, dp[maxn];

vector<ll> g;

char s;

ll a[5][5] = {{0, 1, 2, -1, -1}, {3, 4, 5, 6, -1}, {7, 8, 9, 10, 11}, {12, 13, 14, 15, -1}, {16, 17, 18, -1, -1}};
ll b[5][5] = {{7, 3, 0, -1, -1}, {12, 8, 4, 1, -1}, {16, 13, 9, 5, 2}, {17, 14, 10, 6, -1}, {18, 15, 11, -1, -1}};
ll c[5][5] = {{2, 6, 11, -1, -1}, {1, 5, 10, 15, -1}, {0, 4, 9, 14, 18}, {3, 8, 13, 17, -1}, {7, 12, 16, -1, -1}};

int main(){
	fast_io;
	
	for(ll i = 0; i < 5; i++){
		for(ll j = 0; j < 5; j++){
			x = 0;
			for(ll k = j; k < 5; k++){
				if(a[i][k] == -1) continue;
				x += (1ll << a[i][k]);
				g.pb(x);
			}
		}
	}
	for(ll i = 0; i < 5; i++){
		for(ll j = 0; j < 5; j++){
			if(b[i][j] == -1) continue;
			x = (1ll << b[i][j]);
			for(ll k = j + 1; k < 5; k++){
				if(b[i][k] == -1) continue;
				x += (1ll << b[i][k]);
				g.pb(x);
			}
		}
	}
	for(ll i = 0; i < 5; i++){
		for(ll j = 0; j < 5; j++){
			if(c[i][j] == -1) continue;
			x = (1ll << c[i][j]);
			for(ll k = j + 1; k < 5; k++){
				if(c[i][k] == -1) continue;
				x += (1ll << c[i][k]);
				g.pb(x);
			}
		}
	}
	
	for(ll i = 1; i < (1ll << lg); i++){
		for(ll j = 0; j < g.size(); j++){
			if((i & g[j]) == g[j] && !dp[i ^ g[j]]) dp[i] = 1;
		}
	}
	
	x = 0;
	
	for(ll i = 0; i < 19; i++){
		cin >> s;
		if(s == 'O') x += (1ll << i);
	}
	
	cout << (dp[x] ? "Karlsson" : "Lillebror");
	
	return 0;
}