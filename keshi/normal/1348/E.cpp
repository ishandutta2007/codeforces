//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 510;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a[maxn], b[maxn], c[maxn], x, y, jp, op, dp[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n >> k;
	
	fill(dp[0], dp[0] + maxn, -inf);
	dp[0][0] = 0;
	for(ll i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		c[i] = (c[i - 1] + a[i] + b[i]) % k;
		for(ll j = 0; j < k; j++){
			dp[i][j] = -inf;
			jp = c[i] - j;
			if(jp < 0) jp += k;
			for(ll o = 0; o < k; o++){
				op = c[i - 1] - o;
				if(op < 0) op += k;
				x = j - o;
				if(x < 0) x += k;
				y = jp - op;
				if(y < 0) y += k;
				if(x > a[i] || y > b[i]) continue;
				dp[i][j] = max(dp[i][j], dp[i - 1][o] + (a[i] - x + b[i] - y) / k + (o > j) + (op > jp));
			}
		}
	}
	
	cout << *max_element(dp[n], dp[n] + k);
	
	return 0;
}