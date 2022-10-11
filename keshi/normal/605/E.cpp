//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, v, b;

bool vis[maxn];

ld d[maxn], s[maxn], t[maxn], w[maxn], y[maxn], a[maxn][maxn];

int main(){
	fast_io;
	
	cout << setprecision(10) << fixed;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			cin >> b;
			a[i][j] = (ld)b / 100;
		}
	}
	
	fill(d, d + n, inf);
	fill(w, w + n, inf);
	fill(y, y + n, 1);
	
	d[n] = 0;
	
	for(ll i = 0; i < n; i++){
		ld x = inf;
		for(ll j = 1; j <= n; j++){
			if(!vis[j] && d[j] < x) x = d[j], v = j;
		}
		vis[v] = 1;
		if(v == 1){
			cout << d[1];
			return 0;
		}
		for(ll j = 1; j <= n; j++){
			if(vis[j]) continue;
			if(w[j] <= d[v]) continue;
			s[j] += y[j] * a[j][v] * (d[v] + 1);
			t[j] += y[j] * a[j][v];
			if(t[j]) d[j] = (s[j] + 1 - t[j]) / (t[j]);
			y[j] *= (1 - a[j][v]);
			if(a[j][v]) w[j] = min(w[j], (d[v] + 1) / a[j][v]);
		}
	}
	
	return 0;
}