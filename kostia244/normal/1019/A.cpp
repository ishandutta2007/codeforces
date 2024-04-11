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
const int maxn = 2e5 + 55, mlg = 18, mod =1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vi t[maxn];
ll go(ll x) {
	ll cst = 0, vt = t[1].size();
	vi q;
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j < t[i].size(); j++) {
			if((int)t[i].size()-j >= x)
				cst += t[i][j], vt++;
			else
				q.pb(t[i][j]);
		}
	}
	sort(all(q));
//	cout << x << ":\n";
//	cout << vt << " " << q.size() << " " << cst << "\n";
	for(int i = 0; vt+i<x; i++)
		cst += q[i];
//	cout << vt << " " << q.size() << " " << cst << "\n";
	return cst;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	for(int p, x, i = 0; i < m; i++) {
		cin >> p >> x;
		t[p].pb(x);
	}
	for(int i = 1; i <= n; i++)
		sort(all(t[i]));
	ll ans = 1ll<<60;
	for(int i = 1; i <= m; i++) {
		ans = min(ans, go(i));
	}
	cout<< ans;
	return 0;
}