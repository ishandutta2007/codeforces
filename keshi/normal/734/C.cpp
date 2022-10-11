//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll INF = 8e18;

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

int n, m, k, a[maxn], b[maxn], c[maxn], d[maxn], x, s;

int main(){
	fast_io;
	
	cin >> n >> m >> k;
	cin >> x >> s;
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	for(int i = 0; i < k; i++){
		cin >> c[i];
	}
	for(int i = 0; i < k; i++){
		cin >> d[i];
	}
	ll ans = INF;
	{
		int j = upper_bound(d, d + k, s) - d - 1;
		if(j == -1){
			ans = min(ans, 1ll * n * x);
		}
		else ans = min(ans, 1ll * (n - c[j]) * x);	
	}
	for(int i = 0; i < m; i++){
		if(b[i] > s) continue;
		int j = upper_bound(d, d + k, s - b[i]) - d - 1;
		if(j == -1){
			ans = min(ans, 1ll * n * a[i]);
		}
		else ans = min(ans, 1ll * (n - c[j]) * a[i]);
	}
	cout << ans;
	
	return 0;
}