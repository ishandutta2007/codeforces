#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define ll long long

ll n, a[MAXN], sum[MAXN], ans;
map<ll, ll> m;

int main(){
	fast_io;
	cin >> n;
	ans = 0;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		m[sum[i]] = i;
	}
	for(ll i = 1; i <= n; i++){
		if(m[sum[n] - sum[i]] != 0 && m[sum[n] - sum[i]] <= i){
			ans = max(ans, sum[n] - sum[i]);
		}
	}
	cout << ans;
	return 0;
}