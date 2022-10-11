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

ll n, a[maxn], b[maxn], l[maxn], r[maxn], m, cnt[maxn], dp[maxn];

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		l[i] = a[i] - b[i];
		r[i] = a[i] + b[i];
		cnt[max(0ll, l[i])]++;
		cnt[min(m, r[i]) + 1]--;
	}
	
	for(ll i = 1; i <= m; i++){
		cnt[i] += cnt[i - 1];
	}
	
	for(ll i = m; i > 0; i--){
		dp[i] = inf;
		if(cnt[i]) dp[i] = min(dp[i], dp[i + 1]);
		if(i > 1) dp[i] = min(dp[i], dp[i + 1] + 1);
		for(ll j = 0; j < n; j++){
			if(l[j] >= i) dp[i] = min(dp[i], dp[r[j] + l[j] - i + 1] + l[j] - i);
		}
	}
	
	cout << dp[1];
	
	return 0;
}