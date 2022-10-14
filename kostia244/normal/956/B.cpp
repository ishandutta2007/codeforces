#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e2 + 5, mlg = 18, mod =1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, u;
using ld = long double;
vi a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> u;
	a.resize(n);
	for(auto &i : a) cin >> i;
	int j = 2;
	ld ans = -30;
	for(int i = 1; i < n; i++) {
		while(j<a.size()&&a[j]-a[i-1]<=u) j++;
		j--;
		if(j>i) {
			ans = max(ans, (ld)(a[j]-a[i])/(ld)(a[j]-a[i-1]));
		}
	}
if(ans<0) cout << -1;
else cout << fixed << setprecision(15) << ans;
	return 0;
}