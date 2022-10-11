//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e4 + 10;
const ll tof = 350;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, d, l, r, x, ans, a[maxn], dp[tof][maxn];

int main(){
	fast_io;
	
	cin >> n >> d;
	
	x = 0;
	r = d;
	while(x < maxn){
		x += r;
		r++;
	}
	
	x = 0;
	l = d;
	while(x < maxn){
		x += l;
		if(l > 1) l--;
	}
	
	for(ll i = 0; i < n; i++){
		cin >> x;
		a[x]++;
	}
	
	for(ll i = 0; i < tof; i++){
		fill(dp[i], dp[i] + maxn, -inf);
	}
	
	dp[d - l][d] = a[d];
	
	ans = a[d];
	
	for(ll i = d + 1; i < maxn; i++){
		for(ll j = 0; j <= r - l; j++){
			if(i - j - l < 0) continue;
			if(j) dp[j][i] = max(dp[j - 1][i - j - l], max(dp[j][i - j - l], dp[j + 1][i - j - l])) + a[i];
			else dp[j][i] = max(dp[j][i - j - l], dp[j + 1][i - j - l]) + a[i];
			ans = max(ans, dp[j][i]);
		}
	}
	
	cout << ans;
	
	
	return 0;
}