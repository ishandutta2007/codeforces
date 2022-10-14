#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define pi pair<ll, ll>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll
//using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef double ld;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <vi> vvi;
typedef __V <__V<pi>> vvpi;
int n, u, v, k, tk, D;
vvpi g;
vi d, c;

void dfs(int u = 1, int p = 0, int col = 1) {
	for (auto& v : g[u]) {
		if (v.first == p)
			continue;
		c[v.second] = col;
		col = col % D + 1;
		dfs(v.first, u, col);
	}
}

int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> n >> k;
	g.resize(n + 1);
	d.resize(n + 1);
	c.resize(n - 1);
	for (int i = 0; i + 1 < n; i++) {
		cin >> u >> v;
		g[v].eb(u, i);
		g[u].eb(v, i);
		d[u]++;
		d[v]++;
	}
	mii cnt;
	for (auto i : d)
		if(i)
			cnt[i]++;
	tk = n, D = 1;
	for (auto& i : cnt)
		if (tk > k) {
			tk -= i.second;
			D=i.first;
		}
	cout << D << "\n";
	dfs();
	for (auto i : c)
		cout << i << " ";
}