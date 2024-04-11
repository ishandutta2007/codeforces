//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,sse,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 20, mlg = 18, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ld = long double;
ll n, v1, v2, l, k, g;
ld t1, t2;
ld f(ld x) {
	ld t = 0, bus = 0, ans = 0;
	for(int i = 0; i < g; i++) {
		ld meet = t + (bus-t*v1)/(v1+v2);
		ld meetp = min((ld)l, v1*meet + x);
		t = meet + (ld)min(x, l-meet*v1)/v2;
		bus = min(v1*meet + (ld)x, (ld)l);
		ans = max(ans, t + ((ld)l-meetp)/(ld)v1);
	}
	return max(ans, t);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> v1 >> v2 >> k;
	t1 = (ld)l/v1;
	t2 = (ld)l/v2;
	g = (n+k-1)/k;
	ld x = 0, y = l, a, b;
	while(y-x>1e-8) {
		a = x + (y-x)/3;
		b = y - (y-x)/3;
		if(f(a)>f(b))
			x = a;
		else
			y = b;
	}
	cout << fixed << setprecision(15) << f(x);
	return 0;
}