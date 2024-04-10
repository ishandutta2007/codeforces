//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 210;
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
			fill(a[i].begin(), a[i].end(), -inf);
			if(f) fill(a[i].begin(), a[i].end(), 0);
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
					c[i][j] = max(c[i][j], a[i][k] + b.a[k][j]);
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

ll n, l, a[maxn], g[maxn][26], nxt[maxn][26], par[maxn], t, c[maxn], q[maxn];
string s[maxn];

void cal(){
	ll l = 0, r = 0;
	q[r++] = 0;
	while(l < r){
		ll v = q[l++];
		c[v] += c[par[v]];
		for(ll i = 0; i < 26; i++){
			if(g[v][i]){
				nxt[v][i] = g[v][i];
				if(v) par[nxt[v][i]] = nxt[par[v]][i];
				q[r++] = nxt[v][i];
			}
			else{
				nxt[v][i] = nxt[par[v]][i];
			}
		}
	}
}

int main(){
    fast_io;
    
    cin >> n >> l;
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
	}
	for(ll i = 0; i < n; i++){
		cin >> s[i];
		ll x = 0;
		for(char c : s[i]){
			if(g[x][c - 'a'] == 0) g[x][c - 'a'] = ++t;
			x = g[x][c - 'a'];
		}
		c[x] += a[i];
	}
	cal();
	matrix A(t + 1, t + 1);
	for(ll i = 0; i <= t; i++){
		for(ll j = 0; j < 26; j++){
			A[nxt[i][j]][i] = c[nxt[i][j]];
		}
	}
	A = powmat(A, l);
	matrix B(t + 1, 1);
	B[0][0] = 0;
	A = A * B;
	ll ans = 0;
	for(ll i = 0; i <= t; i++){
		ans = max(ans, A[i][0]);
	}
	cout << ans;
 
    return 0;
}