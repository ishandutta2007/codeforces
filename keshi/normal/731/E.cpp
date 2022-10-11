//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int n, a[maxn], ps[maxn], dp[maxn];

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ps[i] = a[i] + ps[i - 1];
	}
	dp[n] = 0;
	int mx = ps[n];
	for(int i = n - 1; i > 0; i--){
		dp[i] = mx;
		mx = max(mx, ps[i] - dp[i]);
	}
	cout << dp[1];
	
	return 0;
}