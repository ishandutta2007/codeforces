//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll mod;

struct matrix {
	ll n, m;
	vector<vector<ll> > a;
	matrix(ll n, ll m, bool f = 0) : n(n), m(m){
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
};

matrix powmat(matrix a, ll b){
	matrix c(a.n, a.m, 1);
	while(b){
		if(b & 1) c = c * a;
		a = a * a;
		b >>= 1;
	}
	return c;
}
ll n, x, y, a[maxn], s, m, sp;

int main(){
	fast_io;
	
	cin >> n >> x >> y >> mod;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		s = (s + a[i]) % mod;
	}
	if(n == 1){
		cout << a[0] % mod;
		return 0;
	}
	matrix C(1, 1);
	C.set(0, 0, 3);
	C = powmat(C, x);
	s = (s * C.get(0, 0)) % mod;
	C = matrix(2, 2);
	C.set(0, 0, 3);
	C.set(0, 1, 1);
	C.set(1, 1, 1);
	C = powmat(C, x);
	s = ((s - C.get(0, 1) * (a[n - 1] + a[0])) % mod + mod) % mod;
	C = matrix(2, 2);
	C.set(0, 0, 1);
	C.set(0, 1, 1);
	C.set(1, 0, 1);
	C = powmat(C, x);
	matrix M(2, 1);
	M.set(0, 0, 1);
	C = C * M;
	m = (C.get(0, 0) * a[n - 1] + C.get(1, 0) * a[n - 2]) % mod;
	C = matrix(1, 1);
	C.set(0, 0, 3);
	C = powmat(C, y);
	sp = s * C.get(0, 0);
	C = matrix(2, 2);
	C.set(0, 0, 3);
	C.set(0, 1, 1);
	C.set(1, 1, 1);
	C = powmat(C, y);
	sp = ((sp - C.get(0, 1) * (m + a[0])) % mod + mod) % mod;
	cout << sp;
	return 0;
}