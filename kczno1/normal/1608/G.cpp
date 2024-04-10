#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)

typedef long long s64;
const int N = 2e5 + 5, L = 17, D = 1e9 + 7, W = 27;
char s[N];
pair<int, int> seg[N];
int nex_r[N], dy_r[N];
vector<pair<int, char>> lk[N];
int dep[N], f[N][L];
s64 rt_to[N][L], to_rt[N][L], pow_W[N], h[N][L];

void dfs(int x, int fr) {
	f[x][0] = fr;
	dep[x] = dep[fr] + 1;
	for (int i = 1; i < L; ++i) {
		int y = f[x][i - 1];
		f[x][i] = f[y][i - 1];
		rt_to[x][i] = (rt_to[y][i - 1] * pow_W[1 << (i - 1)] + rt_to[x][i - 1]) % D;
		to_rt[x][i] = (to_rt[x][i - 1] * pow_W[1 << (i - 1)] + to_rt[y][i - 1]) % D;
	}
	for (auto pr: lk[x]) {
		int y;
		char c;
		tie(y, c) = pr;
		if (y != fr) {
			rt_to[y][0] = to_rt[y][0] = c;
			dfs(y, x);
		}
	}
}

namespace BIT {
	int c[N];
	void add(int x) {
		for (int i = x; i < N; i += i & -i) ++c[i];
	}
	int query(int x) {
		int ans = 0;
		for (int i = x; i; i -= i & -i) ans += c[i];
		return ans;
	}
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
}
namespace SA {
	int qa[2][N];
	int sa[N], h[N], *rk = qa[0], *tmp = qa[1];
	int cnt[N];
	void get_sa(int n) {
		rep(i, 1, n)++ cnt[s[i]];
		rep(i, 1, 128) cnt[i] += cnt[i - 1];
		per(i, n, 1) sa[cnt[s[i]]--] = i;
		int m = 1;
		rk[sa[1]] = 1;
		rep(i, 2, n) {
			if (s[sa[i]] != s[sa[i - 1]]) ++m;
			rk[sa[i]] = m;
		}

		for (int l = 1; m < n; l *= 2) {
			//rk[i+l]
			int top = 0;
			rep(i, n - l + 1, n) tmp[++top] = i;
			rep(i, 1, n) if (sa[i] > l) tmp[++top] = sa[i] - l;

			//rk[i]
			memset(cnt + 1, 0, m * sizeof(int));
			rep(i, 1, n)++ cnt[rk[i]];
			rep(i, 1, m) cnt[i] += cnt[i - 1];
			per(i, n, 1) sa[cnt[rk[tmp[i]]]--] = tmp[i];

			swap(rk, tmp);
			m = 1;
			rk[sa[1]] = 1;
			rep(i, 2, n) {
				int now = sa[i], last = sa[i - 1];
				if (tmp[now] != tmp[last] || tmp[now + l] != tmp[last + l]) ++m;
				rk[now] = m;
			}
		}

		int l = 0;
		rep(i, 1, n) {
			if (l) --l;

			int now = rk[i];
			while (s[/*sa[now]*/ i + l] == s[sa[now + 1] + l]) ++l;
			h[now] = l;
		}
	}
};

int qu[N], qv[N];
vector<pair<int, int>> lkq[N];
int ans[N], tot;

int get_lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int j = L - 1; j >= 0; --j)
		if (dep[x] - dep[y] & (1 << j)) x = f[x][j];
	if (x == y) return x;
	for (int j = L - 1; j >= 0; --j)
		if (f[x][j] != f[y][j]) {
			x = f[x][j];
			y = f[y][j];
		}
	return f[x][0];
}
int query(int u, int v) {
	//cout<<u<<" "<<v<<endl;
	int lca = get_lca(u, v);

	int du = dep[u] - dep[lca], dv = dep[v] - dep[lca];

	static int _v[L];
	for (int j = 0; j < L; ++j)
		if (dv & (1 << j)) {
			_v[j] = v;
			v = f[v][j];
		}

	auto cmp_le = [&](const pair<int, int>& seg) -> bool {
		int l, r;
		tie(l, r) = seg;
		int nu = u;
		for (int j = 0; j < L; ++j)
			if (du & (1 << j)) {
				//			cout<<nu<<" "<<j<<endl;
				if (h[l][j] != to_rt[nu][j]) {
					while (j) {
						--j;
						if (h[l][j] == to_rt[nu][j]) {
							l += 1 << j;
							nu = f[nu][j];
						}
					}
					return h[l][0] < to_rt[nu][0];
				}
				l += 1 << j;
				nu = f[nu][j];
			}
		for (int j = L - 1; j >= 0; --j)
			if (dv & (1 << j)) {
				int nv = _v[j];
				//			cout<<nv<<" "<<l<<endl;
				if (h[l][j] != rt_to[nv][j]) {
					while (j) {
						--j;
						if (h[l][j] == rt_to[f[nv][j]][j]) {
							l += 1 << j;
						} else
							nv = f[nv][j];
					}
					//					cout << l << " " << nv << " " << h[l][0] << " " << rt_to[nv][0] << endl;
					return h[l][0] < rt_to[nv][0];
				}
				l += 1 << j;
			}
		return 0;
	};
	auto cmp_eq = [&](const pair<int, int>& seg) -> bool {
		int l, r;
		tie(l, r) = seg;
		int nu = u;
		for (int j = 0; j < L; ++j)
			if (du & (1 << j)) {
				//cout << l << " " << nu << " " << h[l][j] << " " << to_rt[nu][j] << endl;
				if (h[l][j] != to_rt[nu][j])
					return 0;
				l += 1 << j;
				nu = f[nu][j];
			}
		for (int j = L - 1; j >= 0; --j)
			if (dv & (1 << j)) {
				int nv = _v[j];
				//cout << j << " " << nv << " " << h[l][j] << " " << to_rt[nv][j] << " " << nv << endl;
				if (h[l][j] != rt_to[nv][j]) return 0;
				l += 1 << j;
			}
		return 1;
	};

	// find first seg[i] >= (u,v)
	int l = 0, r = tot + 1;
	//l:< r:>=
	while (l + 1 != r) {
		int mid = (l + r) / 2;
		if (cmp_le(seg[mid]))
			l = mid;
		else
			r = mid;
	}
	//cout << l << endl;
	int ans = -BIT::query(l);
	// find first seg[i] > (u,v)
	r = tot + 1;
	//l:<= r:>
	while (l + 1 != r) {
		int mid = (l + r) / 2;
		if (cmp_eq(seg[mid]))
			l = mid;
		else
			r = mid;
		//cout << l << " " << r << endl;
	}
	return ans + BIT::query(l);
}

int main() {
#ifdef kcz
	freopen("1.in", "r", stdin);
#endif
	pow_W[0] = 1;
	for (int i = 1; i < N; ++i) pow_W[i] = pow_W[i - 1] * W % D;
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i < n; ++i) {
		int u, v;
		static char c[10];
		scanf("%d%d%s", &u, &v, c);
		lk[u].push_back({ v, *c });
		lk[v].push_back({ u, *c });
	}
	dfs(1, 0);
	for (int i = 1; i <= m; ++i) {
		int t = dy_r[i - 1] + 2;
		scanf("%s", s + t);
		dy_r[i] = t + strlen(s + t) - 1;
		for (int j = t; j <= dy_r[i]; ++j) nex_r[j] = dy_r[i];
		for (int j = dy_r[i]; j >= t; --j) {
			h[j][0] = s[j];
			for (int k = 1; k < L; ++k) {
				if (j + (1 << k) - 1 <= dy_r[i])
					h[j][k] = (h[j][k - 1] * pow_W[1 << (k - 1)] + h[j + (1 << k - 1)][k - 1]) % D;
				else
					h[j][k] = -1;
			}
		}
	}
	SA::get_sa(dy_r[m]);
	tot = 0;
	static int np[N];
	for (int i = 1; i <= dy_r[m]; ++i) {
		int j = SA::sa[i];
		if (nex_r[j])
			seg[np[j] = ++tot] = { j, nex_r[j] };
	}
	//for (int i = 1; i <= tot; ++i) cout << seg[i].first << " " << seg[i].second << endl;
	for (int i = 1; i <= q; ++i) {
		int u, v, l, r;
		scanf("%d%d%d%d", &u, &v, &l, &r);
		//	cout<<l<<" "<<r<<endl;
		qu[i] = u;
		qv[i] = v;
		lkq[l - 1].push_back({ i, -1 });
		lkq[r].push_back({ i, 1 });
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = dy_r[i - 1] + 2; j <= dy_r[i]; ++j) {
			BIT::add(np[j]);
		}
		for (auto pr: lkq[i]) {
			int j, w;
			tie(j, w) = pr;
			ans[j] += query(qu[j], qv[j]) * w;
		}
	}
	for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
}