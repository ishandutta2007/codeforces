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
#define X first
#define Y second

ll n, a, cnt[MAXN], dp[MAXN];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		cnt[a]++;
	}
	
	dp[1] = cnt[1];
	
	for(ll i = 2; i <= 100000; i++){
		dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
	}
	
	cout << dp[100000];
	
	return 0;
}