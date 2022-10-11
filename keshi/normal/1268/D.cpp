//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2020;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, d[maxn], a[maxn];
bool g[maxn][maxn];

void Do(ll v){
	for(ll i = 1; i <= n; i++){
		if(v == i) continue;
		if(g[v][i]){
			d[v]--;
			d[i]++;
		}
		else{
			d[v]++;
			d[i]--;
		}
		g[v][i] ^= 1;
		g[i][v] ^= 1;
	}
}
bool check(){
	for(ll i = 0; i < n; i++){
		a[i] = d[i + 1];
	}
	sort(a, a + n, greater<ll>());
	ll x = 0;
	for(ll i = 0; i < n - 1; i++){
		x += 2 * a[i] - (n - 1);
		if(x == (i + 1) * (n - i - 1)) return 0;
	}
	return 1;
}

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		string s;
		cin >> s;
		for(ll j = 1; j <= n; j++){
			d[i] += g[i][j] = (s[j - 1] == '1');
		}
	}
	if(check()){
		cout << "0 1";
		return 0;
	}
	if(n < 10){
		ll ans = n + 1, cnt = 0;
		for(ll i = 0; i < (1 << n); i++){
			ll c = 0;
			for(ll j = 0; j < n; j++){
				if((i >> j) & 1){
					c++;
					Do(j + 1);
				}
			}
			if(check()){
				if(c < ans){
					ans = c;
					cnt = 0;
				}
				if(c == ans) cnt++;
			}
			for(ll j = 0; j < n; j++){
				if((i >> j) & 1){
					Do(j + 1);
				}
			}
		}
		if(ans == n + 1){
			cout << -1;
			return 0;
		}
		for(ll j = 1; j <= ans; j++){
			cnt = cnt * j % mod;
		}
		cout << ans << " " << cnt;
		return 0;
	}
	ll cnt = 0;
	for(ll i = 1; i <= n; i++){
		Do(i);
		if(check()) cnt++;
		Do(i);
	}
	cout << 1 << " " << cnt;
	
	return 0;
}