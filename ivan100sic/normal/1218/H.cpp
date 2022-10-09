#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a[200005], q, ans[200005], root[200005], len[200005];
int cidx[200005], hang[200005];
ll m[200005];
basic_string<int> inv[200005], qry[200005];
basic_string<int> root_inv[200005], occ[200005], hang_inv[200005];
bool st[200005], cyc[200005];

void dfs1(int x) {
	int y = a[x];
	st[x] = 1;
	if (root[y]) {
		root[x] = root[y];
	} else if (st[y]) {
		root[x] = x;
	} else {
		dfs1(y);
		root[x] = root[y];
	}
	st[x] = 0;
}

int el[200005], er[200005], et, dub[200005];

void dfs2(int x, int h) {
	el[x] = et++;
	hang[x] = h;
	hang_inv[h] += x;
	for (int y : inv[x]) {
		if (!cyc[y]) {
			dub[y] = dub[x] + 1;
			dfs2(y, h);
		}
	}
	er[x] = et;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		inv[a[i]] += i;
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		int y;
		cin >> m[i] >> y;
		qry[y] += i;
	}

	for (int i=1; i<=n; i++)
		if (!root[i])
			dfs1(i);

	for (int i=1; i<=n; i++)
		root_inv[root[i]] += i;

	for (int i=1; i<=n; i++) {
		if (i == root[i]) {
			int l = 1;
			cyc[i] = 1;
			for (int j=a[i]; j!=i; j=a[j]) {
				cidx[j] = l;
				l++;
				cyc[j] = 1;
			}
			len[i] = l;
		}
	}

	for (int i=1; i<=n; i++) {
		if (cyc[i]) {
			dfs2(i, i);
		}
	}

	for (int i=1; i<=n; i++) {
		occ[dub[i]] += el[i];
	}

	for (int i=0; i<=n; i++)
		sort(occ[i].begin(), occ[i].end());

	for (int x=1; x<=n; x++) {
		if (!cyc[x]) {
			for (int i : qry[x]) {
				int d = min(200001ll, m[i] + dub[x]);
				auto it1 = lower_bound(occ[d].begin(), occ[d].end(), el[x]);
				auto it2 = lower_bound(occ[d].begin(), occ[d].end(), er[x]);
				ans[i] = it2 - it1;
			}
		}
	}

	for (int x=1; x<=n; x++) {
		if (x == root[x]) {
			int sz = root_inv[x].size(), l = len[x];
			deque<int> w(sz);
			for (int y : root_inv[x]) {
				int h = hang[y];
				w[dub[y] + (cidx[h] == 0 ? 0 : l-cidx[h])]++;
			}
			for (int i=l; i<sz; i++)
				w[i] += w[i-l];

			for (int _i=0, y=x; _i<l; _i++) {
				for (int i : qry[y]) {
					ans[i] = w[m[i] >= sz ? m[i]-(m[i]-sz)/l*l-l : m[i]];
				}
				y = a[y];
				w.push_front(0);
				for (int z : hang_inv[y])
					w[dub[z]]++;
				w.pop_back();
			}
		}
	}

	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}