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

ll n, a[MAXN], l[MAXN], r[MAXN], dp[MAXN], ans;

int main(){
	fast_io;
	
	cin >> n;
	
	a[0] = 0;
	a[n + 1] = INF;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	l[1] = 1;
	
	for(ll i = 2; i <= n; i++){
		if(a[i] > a[i - 1]){
			l[i] = l[i - 1] + 1;
		}
		else{
			l[i] = 1;
		}
	}
	
	r[n] = 1;
	
	for(ll i = n - 1; i > 0; i--){
		if(a[i] < a[i + 1]){
			r[i] = r[i + 1] + 1;
		}
		else{
			r[i] = 1;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		if(a[i + 1] - a[i - 1] > 1){
			dp[i] = l[i - 1] + r[i + 1] + 1;
		}
		else{
			dp[i] = max(l[i - 1], r[i + 1]) + 1;
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	
	return 0;
}