//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> cd;

const ll maxn = 2e6;
const ll mod = 998244353;
const ll inf = 1e18;
const ld pi = acos(-1);

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int rev[maxn];

void ntt(ll *a, ll lg, bool inv = 0){
	int n = (1 << lg);
	for(int i = 0; i < n; i++){
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
		if(i < rev[i]) swap(a[i], a[rev[i]]);
	}
	for(int len = 1; len < n; len <<= 1){
        ll wn = pw(5, mod / 2 / len);
        if(inv) wn = pw(wn, mod - 2);
		for(int i = 0; i < n; i += (len << 1)){
			ll w = 1;
			for(int j = i; j < i + len; j++){
				ll v = a[j], u = w * a[j + len] % mod;
				a[j] = (v + u) % mod;
				a[j + len] = (v - u) % mod;
				w = w * wn % mod;
			}
		}
	}
	if(inv){
		ll nn = pw(n, mod - 2);
		for(ll i = 0; i < n; i++){
			a[i] = a[i] * nn % mod;
		}
	}
	return;
}

int n, m, k, a[maxn], b[maxn], q[maxn], ans[maxn];
int pp[maxn];

ll A[maxn], B[maxn];

int main(){
	fast_io;
	
	for(ll i = 1; i < maxn; i++){
		pp[i] = pw(i, mod - 2);
	}
	
	cin >> n >> k;
	for(ll i = 0; i < n; i++){
		ll x;
		cin >> x; 
		a[x]++;
	}
	for(ll i = 0; i < k; i++){
		cin >> b[i];
	}
	cin >> m;
	for(ll i = 0; i < m; i++){
		cin >> q[i];
	}
	for(ll o = 0; o < k; o++){
		ll x = 0, y = 0;
		for(ll i = 0; i < b[o]; i++){
			if(a[i] == 0) continue;
			if(a[i] == 1) x++;
			else y++;
		}
		fill(A, A + maxn, 0);
		fill(B, B + maxn, 0);
		ll p = 1;
		for(ll i = 0; i <= x; i++){
			A[i] = p;
			p = p * 2 * (x - i) % mod * pp[i + 1] % mod;
		}
		p = 1;
		for(ll i = 0; i <= y + y; i++){
			B[i] = p;
			p = p * (y + y - i) % mod * pp[i + 1] % mod;
		}
		ntt(A, 20, 0);
		ntt(B, 20, 0);
		for(ll i = 0; i < (1 << 20); i++){
			A[i] = A[i] * B[i] % mod;
		}
		ntt(A, 20, 1);
		for(ll i = 0; i < m; i++){
			ll j = (q[i] >> 1) - b[o] - 1;
			if(j >= 0) ans[i] = (ans[i] + A[j]) % mod;
		}
	}
	for(ll i = 0; i < m; i++){
		cout << (ans[i] + mod) % mod << "\n";
	}
	
	return 0;
}