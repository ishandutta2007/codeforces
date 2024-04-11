#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mlg = 18, mod = 1e9 + 7;
vi a, b, c, d;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> k;
	char t;
	for(int i = 0; i < k; i++) {
		cin >> t;
		a.pb(t-'a');
	}
	for(int i = 0; i < k; i++) {
		cin >> t;
		b.pb(t-'a');
	}
	reverse(all(a));
	reverse(all(b));
	a.pb(0);
	b.pb(0);
	c.resize(k+1);
	d.resize(k+1);
	int co = 0;
	for(int i = 0; i <= k; i++) {
		c[i] = a[i]+b[i]+co;
		co = 0;
		if(c[i]>=26) {
			co = c[i]/26;
			c[i]%=26;
		}
	}
	co = 0;
	for(int i = k; i>=0; i--) {
		c[i] += co;
		d[i] = c[i]/2;
		co = 26*(c[i]&1);
	}
	d.pop_back();
	reverse(all(d));
	for(int i = 0; i < k; i++) {
		cout << char(d[i]+'a');
	}
}