#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e5 + 5, mod = 1e9 + 7;
int dp[maxn];
int odd(int n) {
	if(n==3||n==1) return 1;
	if(n==0||n==2) return 0;
	if(n>=5&&(n%2)) return 0;
	for(int i = 2; 3ll*(1ll<<i) <= n; i+=2) {
		if(3ll*(1ll<<i)==n) return 1;
	}
	for(ll t = 8; t <= n; t*=4) {
		if(t==n) return 1;
	}
	for(int i = 1; n>>i; i+=2) {
		ll t = (1ll<<i)-1;
		if(n&t) continue;
		if((n>>i)>3&&((n>>i)%2)) return 1;
	}
	return 2;
}
int even(int n) {
	if(n==0) return 0;
	if(n==1) return 1;
	if(n==2) return 2;
	return (n+1)&1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, res = 0;
	cin >> n >> k;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		if(k&1) res^=odd(t);
		else res^=even(t);
	}
	cout << (res?"Kevin":"Nicky");
}