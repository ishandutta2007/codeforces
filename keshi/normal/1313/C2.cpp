//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], l[maxn], r[maxn], dp[maxn], pd[maxn], x, ans, m, b[maxn];

vector<ll> v;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	v.pb(0);
	
	for(ll i = 1; i <= n; i++){
		while(a[i] < a[v.back()]) v.pop_back();
		l[i] = v.back();
		v.pb(i);
	}
	
	v.clear();
	
	v.pb(n + 1);
	
	for(ll i = n; i > 0; i--){
		while(a[i] < a[v.back()]) v.pop_back();
		r[i] = v.back();
		v.pb(i);
	}
	
	for(ll i = 1; i <= n; i++){
		dp[i] = dp[l[i]] + (i - l[i]) * a[i];
	}
	
	for(ll i = n; i > 0; i--){
		pd[i] = pd[r[i]] + (r[i] - i) * a[i];
	}
	
	for(ll i = 1; i <= n; i++){
		if(ans < dp[i] + pd[i] - a[i]){
			ans = dp[i] + pd[i] - a[i];
			x = i;
		}
	}
	
	b[x] = a[x];
	m = a[x];
	
	for(ll j = x - 1; j > 0; j--){
		b[j] = min(a[j], m);
		m = min(a[j], m);
	}
	m = a[x];
	for(ll j = x + 1; j <= n; j++){
		b[j] = min(a[j], m);
		m = min(a[j], m);
	}
	
	for(ll i = 1; i <= n; i++){
		cout << b[i] << " ";
	}
	
	return 0;
}