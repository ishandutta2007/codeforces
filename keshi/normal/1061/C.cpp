// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, a[MAXN], ans[MAXN];

void adj(ll x){
	ll j;
	for(ll i = 1; i * i < x; i++){
		if(x % i == 0 && x / i <= n){
			ans[x / i] += ans[x / i - 1];
			ans[x / i] %= MOD;
		}
		j = i;
	}
	
	if((j + 1) * (j + 1) == x){
		j++;
	}
	
	for(ll i = j; i > 0; i--){
		if(x % i == 0 && i <= n){
			ans[i] += ans[i - 1];
			ans[i] %= MOD;
		}
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	ans[0] = 1;
	for(ll i = 0; i < n; i++){
		adj(a[i]);
	}
	
	ans[0] = 0;
	for(ll i = 1; i <= n; i++){
		ans[0] += ans[i];
		ans[0] %= MOD;
	}
	
	cout << ans[0];
	
	return 0;
}