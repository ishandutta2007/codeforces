#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,ssse3,sse2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
const int maxn = 1<<17;
int n, curx[maxn], dg[maxn], xr[maxn];
vpi e;
set<pair<pi, int>> a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for(int x, y, i = 0; i < n; i++) {
		cin >> dg[i] >> xr[i];
		if(dg[i])
		a.insert({{dg[i], xr[i]}, i});
	}
	while(!a.empty()) {
		int u = a.begin()->second;
		a.erase(a.begin());
		int p = xr[u];
		a.erase({{dg[p], xr[p]}, p});
		e.pb({u, p});
		dg[p]--;
		xr[p]^=u;
		if(dg[p])
			a.insert({{dg[p], xr[p]}, p});
	}
	cout << e.size() << "\n";
	for(auto i : e) cout << i.first << " " << i.second << "\n";
	return 0;
}