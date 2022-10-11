//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k[4], a[maxn], x, dp[4][maxn], ps[4][maxn], cnt[4][maxn];

int main(){
	fast_io;
	
	cin >> k[1] >> k[2] >> k[3];
	
	n = k[1] + k[2] + k[3];
	
	for(ll i = 1; i < 4; i++){
		for(ll j = 0; j < k[i]; j++){
			cin >> x;
			a[x] = i;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= 3; j++){
			cnt[j][i] = cnt[j][i - 1] + (a[i] != j);
		}
	}
	
	for(ll i = 1; i <= n; i++){
		ps[1][i] = min(ps[1][i - 1], cnt[1][i] - cnt[2][i]);
		dp[2][i] = ps[1][i] + cnt[2][i];
		ps[2][i] = min(ps[2][i - 1], dp[2][i] - cnt[3][i]);
	}
	
	cout << ps[2][n] + cnt[3][n];
	
	return 0;
}