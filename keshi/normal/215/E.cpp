//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll l, r, l1, r1, l2, r2, ans, dp[maxn][maxn];

ll cal(ll x, ll k, ll t){
	ll y = 0;
	for(ll i = 0; i < t; i++){
		y = (y << k) + x;
	}
	return y;
}

int main(){
	fast_io;
	
	cin >> l >> r;
	
	for(ll i = 1; i <= 60; i++){
		l1 = max(l, (1ll << (i - 1)));
		r1 = min(r, (1ll << i) - 1);
		if(l1 > r1) continue;
		for(ll k = 1; k < i; k++){
			if(i % k) continue;
			l2 = (l1 >> (i - k));
			r2 = (r1 >> (i - k));
			if(cal(l2, k, i / k) < l1) l2++;
			if(cal(r2, k, i / k) > r1) r2--;
			dp[i][k] += r2 - l2 + 1;
			for(ll j = 1; j < k; j++){
				if(k % j == 0) dp[i][k] -= dp[i][j];
			}
			ans += dp[i][k];
		}
	}
	
	cout << ans;
	
	return 0;
}