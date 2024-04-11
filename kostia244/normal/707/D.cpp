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
using vvi = vector<vector<ll>>;
const ll mod = (1e9 + 7);
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
int cutl = -1, cutr = -1, T = 1, cnt;
struct req {
	int a, b, c;
};
oset l, r;
int n, m, q, mat[1010][1010];
int cntr[1010], msk[1010];

bool exec(int a, int b, int c) {
	if (!a || a == 4)
		return false;
	if (a < 3) {
		if ((a == 1 && mat[b][c] == msk[b])
				|| (a == 2 && mat[b][c] != msk[b])) {
			mat[b][c] ^= 1;
			cntr[b] += mat[b][c] != msk[b] ? 1 : -1;
			cnt += mat[b][c] != msk[b] ? 1 : -1;
			return true;
		}
	} else if (a == 3) {
		cnt += m - 2 * cntr[b];
		cntr[b] = m - cntr[b];
		msk[b] ^= 1;
		return true;
	}
	return false;
}
void rexec(int a, int b, int c) {
	if (a < 3) {
		mat[b][c] ^= 1;
		cntr[b] += mat[b][c] != msk[b] ? 1 : -1;
		cnt += mat[b][c] != msk[b] ? 1 : -1;
	} else if (a == 3) {
		cnt += m - 2 * cntr[b];
		cntr[b] = m - cntr[b];
		msk[b] ^= 1;
	}
}
vvi g;
req zz[101000];
int ans[101000];
void dfs(int v) {
	int redo = 0;
	if (v) {
		redo = exec(zz[v].a, zz[v].b, zz[v].c);
	}
	for (auto i : g[v])
		dfs(i);
	ans[v] = cnt;
	if (redo) {
		rexec(zz[v].a, zz[v].b, zz[v].c);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	g.resize(q + 1);
	int p;
	for (int a, b, c, i = 1; i <= q; i++) {
		cin >> a >> b;
		if (a < 3)
			cin >> c;
		zz[i] = {a, b, c};
		if (a == 4) {
			p = b;
		} else
			p = i - 1;
		g[p].pb(i);
	}
	dfs(0);
	for (int i = 1; i <= q; i++)
		cout << ans[i] << "\n";
}