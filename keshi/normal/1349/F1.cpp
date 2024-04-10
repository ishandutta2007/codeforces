//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5100;
const ll mod = 998244353;
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
FastMod M(mod);

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dp[maxn], s[2][maxn];

int main(){
	fast_io;
	
	cin >> n;
	if(n == 1){
		cout << 1;
		return 0;
	}
	dp[1] = 1;
	s[1][1] = 1;
	for(ll i = 2; i <= n; i++){
		for(ll j = 1; j <= (i + 1) / 2; j++){
			s[i & 1][j] = M.od(s[i - 1 & 1][j] * j + s[i - 1 & 1][j - 1] * (i + 1 - j));
		}
		for(ll j = n; j > (i + 1) / 2; j--){
			s[i & 1][j] = s[i & 1][i - j + 1];
		}
		for(ll j = 1; j <= i; j++){
			dp[j] = M.od(dp[j] * i + s[i & 1][j]);
		}
	}
	for(ll i = 1; i <= n; i++){
		cout << dp[i] << " ";
	}
	
	return 0;
}