#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll a, b, dp[200][200];

ll f(ll x, ll y){
	if(x < 1 || y < 1 || (x < 2 && y < 2)){
		return 0;
	}
	if(!dp[x][y]){
		dp[x][y] = max(f(x + 1, y - 2), f(x - 2, y + 1)) + 1;
	}
	return dp[x][y];
}

int main(){
	fast_io;
	cin >> a >> b;
	cout << f(a, b);
	return 0;
}