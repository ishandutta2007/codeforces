#include <bits/stdc++.h>
#ifdef LOCAL
#define dbg(x) (cerr << "ln " << __LINE__ << ": " << #x << " = " << (x) << '\n')
#else
#define dbg(x) {}
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct grana {
	int y, l;
};

int n, k;
vector<grana> e[100005];

int d[100005], pre[100005];

void bfs(int x, int* d, int* pre) {
	fill(d+1, d+n+1, -1);
	fill(pre+1, pre+n+1, -1);
	d[x] = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front(); q.pop();
		for (auto g : e[x])
			if (d[g.y] == -1) {
				d[g.y] = d[x] + g.l;
				pre[g.y] = x;
				q.push(g.y); 
			}
	}
}

vector<int> stek;
bool absorb[100005];

int rd[100005], rp[100005];

void preddfs(int x, int p) {
	rp[x] = p;
	for (grana g : e[x])
		if (g.y != p) {
			rd[g.y] = rd[x] + g.l;
			preddfs(g.y, x);
		}
}

void rekdod(int x) {
	if (x == -1)
		return;
	if (absorb[x])
		return;
	absorb[x] = true;
	rekdod(rp[x]);
}

// dizi sve cvorove za najvise tgt ka rootu, zabelezi cvor
void dfs(int x, int p, int i, int tgt) {
	while (i+1 < (int)stek.size()) {
		if (rd[x] - rd[stek[i]] > tgt)
			i++;
		else
			break;
	}

	// cerr << x << ' ' << stek[i] << '\n';

	rekdod(stek[i]);
	for (grana g : e[x])
		if (g.y != p) {
			stek.push_back(g.y);
			dfs(g.y, x, i, tgt);
			stek.pop_back();
		}
}

bool probaj(int rr, int tgt) {
	fill(absorb+1, absorb+n+1, 0);

	rd[rr] = 0;
	preddfs(rr, -1);
	rp[rr] = -1;
	stek = {rr};
	dfs(rr, -1, 0, tgt);

	int ba = 0;
	for (int i=1; i<=n; i++) {
		if (!absorb[i])
			continue;
		ba++;
		int susa = 0;
		for (grana g : e[i]) {
			if (absorb[g.y])
				susa++;
		}
		if (susa >= 3)
			return false;
	}
	return ba <= k;
}

bool probaj(int r0, int r1, int tgt) {
	if (probaj(r0, tgt))
		return true;

	return probaj(r1, tgt);
}

void kajedan(int r0, int r1) {
	int sol = 1123123123;
	bfs(r0, d, pre);
	sol = min(sol, *max_element(d+1, d+n+1));
	bfs(r1, d, pre);
	sol = min(sol, *max_element(d+1, d+n+1));
	cout << sol;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		e[u].push_back({v, l});
		e[v].push_back({u, l});
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	// dijametar
	int r0=0, r1=0;
	{
		bfs(1, d, pre);
		int x0 = max_element(d+1, d+n+1) - d;
		bfs(x0, d, pre);
		int x1 = max_element(d+1, d+n+1) - d;

		int t = x1;
		while (pre[t] != -1) {
			int q = pre[t];
			if (d[q]*2 == d[x1]) {
				r0 = r1 = q;
				break;
			} else if (d[q]*2 < d[x1]) {
				r0 = t;
				r1 = q;
				break;
			}
			t = q;
		}
	}

	if (k == 1)
		kajedan(r0, r1);

	if (r0 != r1) {
		rd[r0] = 0;
		preddfs(r0, r1);
		rd[r1] = 0;
		preddfs(r1, r0);
		rp[r0] = -1;
		rp[r1] = -1;
	} else {
		rd[r0] = 0;
		preddfs(r0, -1);
		rp[r0] = -1;
	}

	// cerr << "r " << r0 << ' ' << r1 << '\n';
	// for (int i=1; i<=n; i++) {
	// 	cerr << i << ' ' << rd[i] << ' ' << rp[i] << '\n';
	// }

	if (0) {
		probaj(r0, r1, 4);
	} else {
		// binarna
		int lo = 0, hi = 1e9+7, ok = hi;
		while (lo <= hi) {
			int tgt = (lo + hi) / 2;
			if (probaj(r0, r1, tgt)) {
				ok = tgt;
				hi = tgt - 1;
			} else {
				lo = tgt + 1;
			}
		}
		cout << ok << '\n';
	}

}