//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 200;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

struct matrix{
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
	vector<ll>& operator[](ll i){
		return a[i];
	}
	matrix operator * (const matrix &b){
		assert (m == b.n);
		matrix c = matrix(n, b.m);
		for(ll i = 0; i < n; i++){
			for(ll k = 0; k < m; k++){
				for(ll j = 0; j < b.m; j++){
					c[i][j] = (c[i][j] + a[i][k] * b.a[k][j]) % mod;
				}
			}
		}
		return c;
	}
	matrix operator + (const matrix &b){
		assert((n == b.n) && (m == b.m));
		matrix c = matrix(n, m);
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < m; j++){
				c[i][j] = a[i][j] + b.a[i][j];
				if(c[i][j] >= mod) c[i][j] -= mod;
			}
		}
		return c;
	}
	void print(){
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < m; j++){
				cout << a[i][j] << " ";
			}
			cout << '\n';
		}
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

ll n, k, a[maxn], ans;
bool ok[maxn][maxn];

int main(){
    fast_io;
    
    cin >> n >> k;
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
	}
	matrix A(n, n);
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			A[i][j] = ll(__builtin_popcountll(a[i] ^ a[j]) % 3 == 0);
		}
	}
	A = powmat(A, k - 1);
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			ans = (ans + A[i][j]) % mod;
		}
	}
	cout << (ans + mod) % mod;
 
    return 0;
}