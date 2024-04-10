// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 100;
const long long MOD = 998244353;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define it map<ll, ll>::iterator
#define it2 map<pll, ll>::iterator

ll n, f[MAXN], k, l, o;
pll a[MAXN];
map<ll, ll> c, d;
map<pll, ll> g;
bool isSorted;

int main(){
	fast_io;
	
	f[0] = 1;
	for(ll i = 1; i < MAXN; i++){
		f[i] = (f[i - 1] * i) % MOD;
	}
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F >> a[i].S;
		c[a[i].F]++;
		d[a[i].S]++;
		g[a[i]]++;
	}
	k = 1;
	l = 1;
	
	for(it i = c.begin(); i != c.end(); i++){
		k = (k * f[i -> S]) % MOD;
	}
	
	for(it i = d.begin(); i != d.end(); i++){
		l = (l * f[i -> S]) % MOD;
	}
	
	
	sort(a, a + n);
	
	isSorted = 1;
	
	for(ll i = 0; i < n - 1; i++){
		if(a[i].S > a[i + 1].S){
			isSorted = 0;
		}
	}
	
	if(isSorted){
		o = 1;
		for(it2 i = g.begin(); i != g.end(); i++){
			o = (o * f[i -> S]) % MOD;
		}
	}
	
	//cout << f[n] << " " << k << " " << l << " " << o << endl;
	
	cout << (f[n] - k - l + o + MOD + MOD) % MOD<< endl;
	
	return 0;
}