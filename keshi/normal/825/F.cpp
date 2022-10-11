//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 8e4 + 100;
const ll mod = 1000696969;
const ll mod2 = 1e9 + 7;
const ll inf = 1e18;

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
FastMod M(mod), M2(1000000007);

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dp[maxn], h[2][maxn], c[maxn], p[2][maxn];
vector<ll> d[maxn];

string s;

ll get(ll l, ll r){
	return h[0][r] + mod - M.od(h[0][l] * p[0][r - l]);
}
ll get2(ll l, ll r){
	return h[1][r] + mod2 - M2.od(h[1][l] * p[1][r - l]);
}
bool val(ll a, ll b){
    return (((a - b) / mod) * mod == a - b);
}
bool val2(ll a, ll b){
    return (((a - b) / mod2) * mod2 == a - b);
}

int main(){
	fast_io;
	p[0][0] = 1;
	p[1][0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[0][i] = M.od(p[0][i - 1] * 31);
		p[1][i] = M2.od(p[1][i - 1] * 31);
	}
	for(ll i = 1; i < maxn; i++){
		if(i >= 1) c[i]++;
		if(i >= 10) c[i]++;
		if(i >= 100) c[i]++;
		if(i >= 1000) c[i]++;
	}
	cin >> s;
	n = s.size();
	for(ll i = 1; i <= n; i++){
		h[0][i] = M.od(h[0][i - 1] * 31 + (s[i - 1] - 'a'));
		h[1][i] = M2.od(h[1][i - 1] * 31 + (s[i - 1] - 'a'));
	}
	for(ll i = 0; i < n; i++){
	    d[i].resize(n - i + 10);
	    for(ll j = 1; i + j <= n; j++){
	        d[i][j] = get2(i, i + j);
	    }
	}
	for(ll i = n; i--;){
		dp[i] = inf;
		for(ll j = 1; i + j <= n; j++){
			for(ll k = 1; i + j * k <= n; k++){
				if(val(get(i, i + j * k) * (p[0][j] - 1), get(i, i + j) * (p[0][j * k] - 1)) && val2(d[i][j * k] * (p[1][j] - 1), d[i][j] * (p[1][j * k] - 1))) dp[i] = min(dp[i], dp[i + j * k] + j + c[k]);
			}
		}
	}
	cout << dp[0];
	
	return 0;
}