//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 200;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, x, a[maxn], c, vis[maxn], dp[maxn][2][2];

int main(){
	fast_io;
	
	a[1] = 1;
	a[2] = 2;
	c = 2;
	while(a[c] < inf){
		a[c + 1] = a[c] + a[c - 1];
		c++;
	}
	cin >> n;
	while(n--){
		cin >> x;
		for(ll i = c; i > 0; i--){
			vis[i] = 0;
			if(x >= a[i]){
				vis[i] = 1;
				x -= a[i];
			}
		}
		dp[0][0][0] = 1;
		for(ll i = 1; i < c; i++){
			if(vis[i]){
				dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
				dp[i][0][1] = dp[i][1][1] = 0;
				if(!vis[i - 1] && i >= 2){
					dp[i][0][1] = dp[i - 2][1][0] + dp[i - 2][1][1];
				}
				dp[i][1][0] = dp[i][0][1];
			}
			else{
				dp[i][1][0] = dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
				dp[i][0][1] = dp[i][1][1] = 0;
				if(!vis[i - 1] && i >= 2){
					dp[i][1][1] = dp[i - 2][1][0] + dp[i - 2][1][1];
				}
			}
		}
		cout << dp[c - 1][0][0] + dp[c - 1][0][1] << "\n";
	}
	
	return 0;
}