#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119*(1<<23) + 1);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, x;
	vi a, b, c, d;
	cin >> n >> x;
	a.resize(n+1);
	for(int i = 1; i < n; i++) cin >> a[i];
	b.resize(n+1);
	for(int i = 1; i < n; i++) cin >> b[i];
	c.resize(n+1, 1e12);
	d.resize(n+1, 1e12);
	c[1] = 0;
	d[1] = x;
	for(int i = 1; i <= n; i++) {
		cout << min(c[i], d[i]) << " ";
		if(i==n) continue;
		c[i+1] = min(c[i+1], c[i]+a[i]);
		d[i+1] = min(d[i+1], c[i]+x+b[i]);
		c[i+1] = min(c[i+1], d[i]+a[i]);
		d[i+1] = min(d[i+1], d[i]+b[i]);
	}
}