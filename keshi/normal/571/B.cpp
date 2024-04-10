#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 100;
const int MAXM = 5e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, x, y, a[MAXN], dp[2][MAXM][2], e[2][MAXM][2], ans;

bool val[2][MAXM][2];

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += 1e9 + 1;
	}
	
	sort(a + 1, a + n + 1);
	
	a[n + 1] = INF;
	
	x = n / k;
	y = n % k;
	
	val[0][0][0] = 1;
	
	for(ll i = 1; i <= k; i++){
		for(ll j = 0; j <= y; j++){
			if(val[(i - 1) % 2][j][0] || val[(i - 1) % 2][j][1]){
				val[i % 2][j][0] = 1;
				if(!val[(i - 1) % 2][j][0]){
					dp[i % 2][j][0] = dp[(i - 1) % 2][j][1] + a[e[(i - 1) % 2][j][1] + 1] - a[e[(i - 1) % 2][j][1]];
					e[i % 2][j][0] = e[(i - 1) % 2][j][1] + x;
				}
				else if(!val[(i - 1) % 2][j][1]){
					dp[i % 2][j][0] = dp[(i - 1) % 2][j][0] + a[e[(i - 1) % 2][j][0] + 1] - a[e[(i - 1) % 2][j][0]];
					e[i % 2][j][0] = e[(i - 1) % 2][j][0] + x;
				}
				else if(dp[(i - 1) % 2][j][0] + a[e[(i - 1) % 2][j][0] + 1] - a[e[(i - 1) % 2][j][0]] >= dp[(i - 1) % 2][j][1] + a[e[(i - 1) % 2][j][1] + 1] - a[e[(i - 1) % 2][j][1]]){
					dp[i % 2][j][0] = dp[(i - 1) % 2][j][0] + a[e[(i - 1) % 2][j][0] + 1] - a[e[(i - 1) % 2][j][0]];
					e[i % 2][j][0] = e[(i - 1) % 2][j][0] + x;
				}
				else{
					dp[i % 2][j][0] = dp[(i - 1) % 2][j][1] + a[e[(i - 1) % 2][j][1] + 1] - a[e[(i - 1) % 2][j][1]];
					e[i % 2][j][0] = e[(i - 1) % 2][j][1] + x;
				}
			}
			
			if(val[(i - 1) % 2][j - 1][0] || val[(i - 1) % 2][j - 1][1]){
				val[i % 2][j][1] = 1;
				if(!val[(i - 1) % 2][j - 1][0]){
					dp[i % 2][j][1] = dp[(i - 1) % 2][j - 1][1] + a[e[(i - 1) % 2][j - 1][1] + 1] - a[e[(i - 1) % 2][j - 1][1]];
					e[i % 2][j][1] = e[(i - 1) % 2][j - 1][1] + x + 1;
				}
				else if(!val[(i - 1) % 2][j - 1][1]){
					dp[i % 2][j][1] = dp[(i - 1) % 2][j - 1][0] + a[e[(i - 1) % 2][j - 1][0] + 1] - a[e[(i - 1) % 2][j - 1][0]];
					e[i % 2][j][1] = e[(i - 1) % 2][j - 1][0] + x + 1;
				}
				else if(dp[(i - 1) % 2][j - 1][0] + a[e[(i - 1) % 2][j - 1][0] + 1] - a[e[(i - 1) % 2][j - 1][0]] >= dp[(i - 1) % 2][j - 1][1] + a[e[(i - 1) % 2][j - 1][1] + 1] - a[e[(i - 1) % 2][j - 1][1]]){
					dp[i % 2][j][1] = dp[(i - 1) % 2][j - 1][0] + a[e[(i - 1) % 2][j - 1][0] + 1] - a[e[(i - 1) % 2][j - 1][0]];
					e[i % 2][j][1] = e[(i - 1) % 2][j - 1][0] + x + 1;
				}
				else{
					dp[i % 2][j][1] = dp[(i - 1) % 2][j - 1][1] + a[e[(i - 1) % 2][j - 1][1] + 1] - a[e[(i - 1) % 2][j - 1][1]];
					e[i % 2][j][1] = e[(i - 1) % 2][j - 1][1] + x + 1;
				}
			}
		}
	}
	cout << a[n] - max(dp[k % 2][y][0], dp[k % 2][y][1]);
	
	return 0;
}