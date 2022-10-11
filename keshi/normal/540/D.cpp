//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 110;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll a, b, c;

ld dp[maxn][maxn][maxn], y;

int main(){
	cout << setprecision(10) << fixed;
	fast_io;
	
	cin >> a >> b >> c;
	
	for(ll i = 1; i <= 300; i++){
		for(ll j = 0; j <= i; j++){
			for(ll k = 0; k <= i - j; k++){
				ll o = i - j - k;
				if(j > 100 || k > 100 || o > 100) continue;
				dp[j][k][o] = 0;
				if(i == j){
					dp[j][k][o] = 1;
					continue;
				}
				if(j == 0) continue;
				y = j * (j - 1) / 2 + k * (k - 1) / 2 + o * (o - 1) / 2;
				y /= i * (i - 1) / 2;
				if(j && o) dp[j][k][o] += 2 * j * o * dp[j - 1][k][o] / (i * (i - 1) * (1 - y));
				if(j && k) dp[j][k][o] += 2 * j * k * dp[j][k - 1][o] / (i * (i - 1) * (1 - y));
				if(o && k) dp[j][k][o] += 2 * o * k * dp[j][k][o - 1] / (i * (i - 1) * (1 - y));
			}
		}
	}
	
	cout << dp[a][b][c] << " ";
	
	for(ll i = 1; i <= 300; i++){
		for(ll j = 0; j <= i; j++){
			for(ll k = 0; k <= i - j; k++){
				ll o = i - j - k;
				if(j > 100 || k > 100 || o > 100) continue;
				dp[j][k][o] = 0;
				if(i == k){
					dp[j][k][o] = 1;
					continue;
				}
				if(k == 0) continue;
				y = j * (j - 1) / 2 + k * (k - 1) / 2 + o * (o - 1) / 2;
				y /= i * (i - 1) / 2;
				if(j && o) dp[j][k][o] += 2 * j * o * dp[j - 1][k][o] / (i * (i - 1) * (1 - y));
				if(j && k) dp[j][k][o] += 2 * j * k * dp[j][k - 1][o] / (i * (i - 1) * (1 - y));
				if(o && k) dp[j][k][o] += 2 * o * k * dp[j][k][o - 1] / (i * (i - 1) * (1 - y));
			}
		}
	}
	
	cout << dp[a][b][c] << " ";
	
	for(ll i = 1; i <= 300; i++){
		for(ll j = 0; j <= i; j++){
			for(ll k = 0; k <= i - j; k++){
				ll o = i - j - k;
				if(j > 100 || k > 100 || o > 100) continue;
				dp[j][k][o] = 0;
				if(i == o){
					dp[j][k][o] = 1;
					continue;
				}
				if(o == 0) continue;
				y = j * (j - 1) / 2 + k * (k - 1) / 2 + o * (o - 1) / 2;
				y /= i * (i - 1) / 2;
				if(j && o) dp[j][k][o] += 2 * j * o * dp[j - 1][k][o] / (i * (i - 1) * (1 - y));
				if(j && k) dp[j][k][o] += 2 * j * k * dp[j][k - 1][o] / (i * (i - 1) * (1 - y));
				if(o && k) dp[j][k][o] += 2 * o * k * dp[j][k][o - 1] / (i * (i - 1) * (1 - y));
			}
		}
	}
	
	cout << dp[a][b][c] << " ";
	
	return 0;
}