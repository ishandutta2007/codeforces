#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 3e2 + 10, mlg = 20, mod = 1e9 + 7;
ll n, m, a[10];
ll len(ll x) {
	if(!x) return 1;
	ll lenn = 0;
	while(x) lenn++, x/=7;
	return lenn;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ll x = len(n-1), y = len(m-1);
	if(x+y > 7) return cout << 0, 0;
	for(int i = 0; i < 7; i++) a[i] = i;
	ll ans = 0;
	do {
		ll p = 0, q = 0;
		for(int i = 0; i < x; i++)
			p = (p*7)+a[i];
		for(int i = x; i < x+y; i++)
			q = (q*7)+a[i];
		if(p<n&&q<m) ans++;
	} while(next_permutation(a, a+7));
	for(int i = 1; i <= 7-x-y; i++)
		ans/=i;
	cout << ans;
	return 0;
}