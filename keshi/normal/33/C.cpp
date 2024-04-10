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

ll n, a[MAXN], ps[MAXN], sp[MAXN], dp[MAXN], pd[MAXN], m;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		ps[i] = a[i] + ps[i - 1];
	}
	
	for(ll i = n; i > 0; i--){
		sp[i] = a[i] + sp[i + 1];
	}
	
	m = 0;
	for(ll i = 1; i <= n; i++){
		m = max(m, -2 * ps[i]);
		dp[i] = ps[i] + m;
	}
	
	m = 0;
	
	for(ll i = n; i > 0; i--){
		m = max(m, -2 * sp[i]);
		pd[i] = sp[i] + m;
	}
	
	m = -INF;
	for(ll i = 1; i <= n; i++){
		m = max(m, dp[i] + pd[i + 1]);
	}
	
	cout << m;
	
	return 0;
}