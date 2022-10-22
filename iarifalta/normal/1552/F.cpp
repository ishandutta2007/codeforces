/**
 *	author:	 fractal
 *	timus: 	 288481RF
**/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
#define nl printf("\n");
#define clbuff fflush(stdin);
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pii> spii;
typedef set<pll> spll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, ll> mll;
 
const int N = 1e6 + 2;
const int M = 1e5;
const int mod = 998244353;
const int inf = 2e9 + 3;
const ll INF = 1e18;
const ld pi2 = 2.0 * 3.141592;
const ld pi = 3.141592;
const ld eps = 1e-12;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void files(string s = "main") {
	#ifndef PC
		freopen((s + ".in").c_str(), "r", stdin);
		freopen((s + ".out").c_str(), "w", stdout);
	#endif
}

int add(int a, int b) {
	if (a + b < 0) return a + b + mod;
	if (a + b >= mod) return a + b - mod;
	return a + b;		
}

int mul(int a, int b) {
	return a * 1LL * b % mod;
}

int binpow(int a, int n) {
	int ret = 1;
	while (n) {
		if (n & 1) ret = mul(ret, a);
		a = mul(a, a);
		n >>= 1;
	}
	return ret;
}

int n, s[N];
ll dp[N];
vll x, y;

struct seg {
	ll t[4 * N];
	void upd(ll pos, ll z, ll v = 1, ll l = 1, ll r = n) {
		if(l == r) {
			t[v] = z;
			return;
		}
		ll m = (l + r) >> 1ll;
		if(pos <= m)
			upd(pos, z, v * 2, l, m);
		else
			upd(pos, z, v * 2 + 1, m + 1, r);
		t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;	
   }
   ll get(ll l, ll r, ll v = 1, ll tl = 1, ll tr = n) {
		if(l > tr || tl > r || l > r)
			return 0;   
		if(l <= tl && tr <= r)
			return t[v];
		ll m = (tl + tr) >> 1ll;
		return (get(l, r, v * 2, tl, m) + get(l, r, v * 2 + 1, m + 1, tr)) % mod;
   }
} t;

int main() {                                                       
	speed;
	cin >> n;
	x.resize(n + 1), y.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i] >> s[i];
	}
	ll ans = (x[n] + 1) % mod;
	for (int i = 1; i <= n; ++i) {
		int j = lb(all(x), y[i]) - x.begin();
		dp[i] = (x[i] - y[i] + t.get(j, i - 1)) % mod;
		if (s[i] == 1) {
			ans = (ans + dp[i]) % mod;
		}
		t.upd(i, dp[i]);
	}
	cout << ans << '\n';

}   	
/*                  
4
4 6 1 9
2 5 3 2 
*/