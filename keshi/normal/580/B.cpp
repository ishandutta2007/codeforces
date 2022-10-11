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
#define F first
#define S second

ll n, ps[MAXN], b[MAXN], ans, j, d;

pll a[MAXN];

int main(){
	fast_io;
	
	cin >> n >> d;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].F >> a[i].S;
	}
	
	sort(a + 1, a + n + 1);
	
	for(ll i = 1; i <= n; i++){
		ps[i] = ps[i - 1] + a[i].S;
		b[n - i + 1] = -a[i].F;
	}
	
	for(ll i = 1; i <= n; i++){
		j = n - (upper_bound(b + 1, b + n + 1, -a[i].F - d) - b) + 1;
		ans = max(ans, ps[j] - ps[i - 1]);
	}
	
	cout << ans;
	
	return 0;
}