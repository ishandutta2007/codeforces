#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, h, sol;
int u[100005];
basic_string<int> e[100005], st, vals;

int idx[100005], low[100005], tt;
bool inst[100005];
int id[100005], kk;

void dfs(int x) {
	idx[x] = low[x] = ++tt;
	inst[x] = true;
	st += x;

	for (int y : e[x]) {
		if (idx[y] == 0) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		} else if (inst[y]) {
			low[x] = min(low[x], idx[y]);
		}
	}

	if (idx[x] == low[x]) {
		int sz = 0;
		basic_string<int> deo;
		while (1) {
			int t = st.back();
			st.pop_back();
			deo += t;
			inst[t] = false;
			sz++;
			if (t == x)
				break;
		}

		kk++;
		for (int t : deo)
			id[t] = kk;

		bool ok = true;

		for (int t : deo)
			for (int z : e[t])
				if (id[z] < kk)
					ok = false;

		if (sz < sol && ok) {
			sol = sz;
			vals = deo;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> h;
	for (int i=1; i<=n; i++)
		cin >> u[i];

	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		if ((u[x] + 1) % h == u[y])
			e[x] += y;
		swap(x, y);
		if ((u[x] + 1) % h == u[y])
			e[x] += y;
	}

	sol = n;
	for (int i=1; i<=n; i++)
		vals += i;
	for (int i=1; i<=n; i++)
		if (!idx[i])
			dfs(i);

	cout << sol << '\n';
	for (int x : vals)
		cout << x << ' ';
	cout << '\n';
}