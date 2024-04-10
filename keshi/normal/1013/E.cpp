//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], dp[maxn][maxn], ps[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 0; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			ps[i][j] = inf;
		}
		if(i) dp[i][1] = max(0ll, a[i - 1] - a[i] + 1) + max(0ll, a[i + 1] - a[i] + 1);
	}
	
	ps[1][1] = dp[1][1];
	ps[2][1] = min(dp[2][1], ps[1][1]);
	dp[3][2] = max(0ll, a[2] - min(a[1], a[3]) + 1) + max(0ll, a[4] - a[3] + 1);
	ps[3][1] = min(ps[2][1], dp[3][1]);
	ps[3][2] = dp[3][2];
	
	for(ll i = 4; i <= n; i++){
		for(ll j = 2; j <= (i + 1) / 2; j++){
			dp[i][j] = min(dp[i - 2][j - 1] + max(0ll, min(a[i - 1], a[i - 2] - 1) - a[i] + 1), ps[i - 3][j - 1] + max(0ll, a[i - 1] - a[i] + 1)) + max(0ll, a[i + 1] - a[i] + 1);
			ps[i][j] = min(ps[i - 1][j], dp[i][j]);
		}
		ps[i][1] = min(ps[i - 1][1], dp[i][1]);
	}
	
	for(ll i = 1; i <= (n + 1) / 2; i++){
		cout << ps[n][i] << " ";
	}
	
	return 0;
}