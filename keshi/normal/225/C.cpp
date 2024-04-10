//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a, b, cnt[maxn], dp[maxn][2];

string s[maxn];

int main(){
	fast_io;
	
	cin >> n >> m >> a >> b;
	
	for(ll i = 0; i < n; i++){
		cin >> s[i];
		dp[i + 1][0] = inf;
		dp[i + 1][1] = inf;
	}
	
	for(ll j = 1; j <= m; j++){
		dp[j][0] = inf;
		dp[j][1] = inf;
		cnt[j] = cnt[j - 1];
		for(ll i = 0; i < n; i++){
			cnt[j] += (s[i][j - 1] == '.');
		}
	}
	
	for(ll i = 1; i <= m; i++){
		for(ll j = a; j <= b; j++){
			if(i < j) continue;
			dp[i][0] = min(dp[i][0], dp[i - j][1] + n * j - cnt[i] + cnt[i - j]);
			dp[i][1] = min(dp[i][1], dp[i - j][0] + cnt[i] - cnt[i - j]);
		}
	}
	
	cout << min(dp[m][0], dp[m][1]);
	
	return 0;
}