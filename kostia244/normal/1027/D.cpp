#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1<<21;
const int mod = 998244353, inv2 = (mod+1)/2, rt = 733596141;
using ld = long double;
vi vis, c, p;
int check(int x) {
	vi trail;
	while(!vis[x]) {
		trail.pb(x);
		vis[x] = 1;
		x = p[x];
	}
	reverse(all(trail));
	while(trail.size()&&trail.back()!=x) trail.pop_back();
	if(trail.size()<1) return 0;
	int ans = 1<<30;
	for(auto &i : trail) ans = min(ans, c[i]);
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vis = c = p = vi(n);
	for(auto &i : c) cin >> i;
	for(auto &i : p) cin >> i, i--;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		ans += check(i);
	}
	cout << ans;
}
// 20998782977