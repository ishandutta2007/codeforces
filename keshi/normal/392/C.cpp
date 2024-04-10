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


struct matrice {
	ll n, m;
	vector<vector<ll> > a;
	matrice(ll n, ll m, bool f = 0) : n(n), m(m){
		a.resize(n);
		for(ll i = 0; i < n; i++){
			a[i].resize(m);
			fill(a[i].begin(), a[i].end(), 0);
			if(f) a[i][i] = 1;
		}
		return;
	}
	void set(ll i, ll j, ll x){
		a[i][j] = x;
		return;
	}
	void add(ll i, ll j, ll x){
		a[i][j] = (a[i][j] + x) % mod;
		return;
	}
	ll get(ll i, ll j){
		return a[i][j];
	}
	matrice operator * (const matrice &b){
		matrice c = matrice(n, b.m);
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < b.m; j++){
				for(ll k = 0; k < m; k++) {
					c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
				}
			}
		}
		return c;
	}
};

matrice powmat(matrice a, ll b){
	matrice c(a.n, a.m, 1);
	while(b){
		if(b & 1) c = c * a;
		a = a * a;
		b >>= 1;
	}
	return c;
}

ll C[maxn][maxn];


int main(){
	fast_io;
	ll n, m;
	
	C[0][0] = 1;
	for(ll i = 1; i < maxn; i++){
		C[i][0] = 1;
		for(ll j = 1; j <= i; j++){
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	
	cin >> n >> m;
	
	matrice A(2 * m + 3, 2 * m + 3);
	A.set(0, 0, 1);
	A.set(0, m + 1, 1);
	for(ll i = m + 2; i < m + m + 3; i++){
		A.set(i, i - m - 1, 1);
	}
	for(ll i = 0; i <= m; i++){
		for(ll j = 0; j <= i; j++){
			A.set(i + 1, j + 1, C[i][j]);
			for(ll k = 0; k <= i; k++){
				A.add(i + 1, m + 2 + k, C[i][j] * C[j][k]);
			}
		}
	}
	A = powmat(A, n);
	matrice B(m + m + 3, 1);
	for(ll i = 0; i < m + 2; i++){
		B.set(i + 1, 0, 1);
	}
	A = A * B;
	cout << A.get(0, 0);
	
	return 0;
}