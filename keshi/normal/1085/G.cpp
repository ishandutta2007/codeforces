//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e3 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn][maxn], d[maxn], f[maxn], dp[maxn][maxn], fen1[maxn], fen2[maxn], ans;

bool v1[maxn], v2[maxn];

void upd1(ll x, ll b){
	if(x == 0) return;
	for(; x < maxn; x += x & -x){
		fen1[x] += b;
	}
	return;
}

void upd2(ll x, ll b){
	if(x == 0) return;
	for(; x < maxn; x += x & -x){
		fen2[x] += b;
	}
	return;
}

ll get1(ll x){
	ll b = 0;
	for(; x > 0; x -= x & -x){
		b += fen1[x];
	}
	return b;
}

ll get2(ll x){
	ll b = 0;
	for(; x > 0; x -= x & -x){
		b += fen2[x];
	}
	return b;
}

int main(){
	ll t, x, y;
	fast_io;
	
	f[0] = 1;
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
	}
	for(ll i = 0; i < maxn; i++){
		dp[i][i] = f[i];
		for(ll j = 0; j < i; j++){
			dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j + 1] * (i - j - 1)) % mod;
		}
	}
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	
	for(ll i = 0; i < n; i++){
		t = a[0][i] - 1 - get1(a[0][i] - 1);
		ans = (ans + t * f[n - i - 1]) % mod;
		upd1(a[0][i], 1);
	}
	
	for(ll i = 1; i < n; i++){
		fill(v1, v1 + n + 1, 0);
		fill(v2, v2 + n + 1, 0);
		fill(fen1, fen1 + n + 1, 0);
		fill(fen2, fen2 + n + 1, 0);
		for(ll j = 0; j < n; j++){
			upd1(j + 1, 1);
			upd2(j + 1, 1);
		}
		x = 0;
		for(ll j = 0; j < n; j++){
			t = get1(a[i][j] - 1);
			if(!v1[a[i - 1][j]] && a[i - 1][j] < a[i][j]) t--;
			v2[a[i - 1][j]] = 1;
			if(!v1[a[i - 1][j]]) upd2(a[i - 1][j], -1);
			else x--;
			y = get2(a[i][j] - 1);
			d[i] = (d[i] + y * dp[n - j - 1][x + 1] + (t - y) * dp[n - j - 1][x]) % mod;
			v1[a[i][j]] = 1;
			upd1(a[i][j], -1);
			if(!v2[a[i][j]]) upd2(a[i][j], -1), x++;
		}
		ans = (ans * dp[n][0] + d[i]) % mod;
	}
	
	cout << ans;
	
	return 0;
}