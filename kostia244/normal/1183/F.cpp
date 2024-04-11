//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
void solve() {
	int n;
	vi a;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	sort(rall(a));
	ll y, b, c, d2, d3, d5;
	y= b= c=0;
	d2= d3= d5=0;
	for(auto i : a) {
		if(y==0) {
			y=i;
		} else if(b==0&&y%i) {
			b=i;
		} else if(b!=0&&c==0&&y%i&&b%i) {
			c=i;
		}
		if(i==y/2)d2=1;
		if(i==y/3)d3=1;
		if(i==y/5)d5=1;
	}
	ll ans = y+b+c;
	if(d2&&d3&&d5&&y%2==0&&y%3==0&&y%5==0)
		ans = max(ans, y/2 + y/3 + y/5);
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}