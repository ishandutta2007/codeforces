//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

struct matrix {
	ll n, m;
	vector<vector<ll> > a;
	matrix(ll n, ll m, bool f = 0) : n(n), m(m){
		a.resize(n);
		for(ll i = 0; i < n; i++){
			a[i].resize(m);
			fill(a[i].begin(), a[i].end(), inf);
			if(f) a[i][i] = 0;
		}
		return;
	}
	void set(ll i, ll j, ll x){
		a[i][j] = x;
		return;
	}
	ll get(ll i, ll j){
		return a[i][j];
	}
	matrix operator * (const matrix &b){
		matrix c = matrix(n, b.m);
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < b.m; j++){
				for(ll k = 0; k < m; k++) {
					c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
				}
			}
		}
		return c;
	}
	matrix operator + (const matrix &b){
		matrix c = matrix(n, m);
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				for(ll k = 0; k < n; k++){
					c.set(i, j, min(c.get(i, j), a[i][k] + b.a[k][j]));
				}
			}
		}
		return c;
	}
};

matrix powmat(matrix a, ll b){
	matrix c(a.n, a.m, 1);
	while(b){
		if(b & 1) c = c + a;
		a = a + a;
		b >>= 1;
	}
	return c;
}
ll n, m, a[maxn], b[maxn], dp[maxn][maxn][maxn];

int main(){
	fast_io;
	
	ll x = 30;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(ll i = 0; i < n; i++){
		cin >> b[i];
	}
	for(ll i = 0; i <= x; i++){
		for(ll j = 0; j <= x; j++){
			dp[0][i][j] = inf;
		}
		dp[0][i][i] = 0;
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < x; j++){
			for(ll k = 0; k < x; k++){
				dp[i][j][k] = inf;
				if(j) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k] + a[i - 1]);
				if(j + 1 < x) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + 1][k] + b[i - 1]);
			}
		}
	}
	matrix C(x, x);
	for(ll i = 0; i < x; i++){
		for(ll j = 0; j < x; j++){
			C.set(i, j, dp[n][i][j]);
		}
	}
	C = powmat(C, m);
	cout << C.get(0, 0);
	
	return 0;
}