//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull od(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll cmod = 1;
const ll mod[cmod] = {1000000007};
const ll inf = 1e18;
	
FastMod M[cmod] = {FastMod(1000000007)};

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, h[cmod][maxn], p[cmod][maxn], ps[maxn], l, r, mid;

bool f;

string s;

ll pw(ll pa, ll pb, ll pm){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2, pm);
	pc = M[pm].od(pc * pc);
	if(pb % 2) pc = M[pm].od(pc * pa);
	return pc;
}

int main(){
	fast_io;
	
	for(ll i = 0; i < cmod; i++){
		p[i][0] = 1;
	}
	for(ll i = 1; i < maxn; i++){
		for(ll j = 0; j < cmod; j++){
			p[j][i] = M[j].od(p[j][i - 1] * 31);
		}
	}
	
	cin >> n >> k >> s;
	
	s = ' ' + s;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < cmod; j++){
			h[j][i] = M[j].od(h[j][i - 1] * 31 + (s[i] - 'a'));
		}
	}
	
	for(ll i = 1; i * k <= n; i++){
		f = 1;
		for(ll j = 0; j < cmod; j++){
			if(h[j][i * k] != M[j].od(M[j].od(h[j][i] * (p[j][i * k] - 1)) * pw(p[j][i] - 1, mod[j] - 2, j))) f = 0;
		}
		if(!f) continue;
		l = 0, r = i + 1;
		while(r - l > 1){
			mid = (l + r) / 2;
			f = 1;
			for(ll j = 0; j < cmod; j++){
				if(i * k + mid > n || h[j][mid] != M[j].od(h[j][i * k + mid] + mod[j] - M[j].od(h[j][i * k] * p[j][mid]))) f = 0;
			}
			if(f) l = mid;
			else r = mid;
		}
		ps[i * k]++;
		ps[i * k + l + 1]--;
	}
	
	for(ll i = 1; i <= n; i++){
		ps[i] += ps[i - 1];
		if(ps[i]) cout << 1;
		else cout << 0;
	}
	
	return 0;
}