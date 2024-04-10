#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;

template<class T>
int ask(T a) {
	int k = a.size();
	if (k <= 1)
		return 0;
	cout << "? " << k << '\n';
	for (int i=0; i<k; i++)
		cout << a[i] << " \n"[i == k-1];
	cout << flush;
	int z;
	cin >> z;
	if (z == -1)
		exit(0);
	return z;
}

bool vis1[605];
basic_string<int> e[605];

void dfs1(int x) {
	vis1[x] = true;
	while (1) {
		{
			basic_string<int> a;
			for (int i=1; i<=n; i++)
				if (!vis1[i])
					a += i;
			if (ask(a+x) - ask(a) == 0)
				return;
		}

		int l = 1, r = n-1, o = n;
		while (l <= r) {
			int m = (l+r) >> 1;
			basic_string<int> a;
			for (int i=1; i<=m; i++)
				if (!vis1[i])
					a += i;
			if (ask(a+x) - ask(a) == 0) {
				l = m + 1;
			} else {
				o = m;
				r = m - 1;
			}
		}

		e[x] += o;
		e[o] += x;
		dfs1(o);
	}
}

int cl[605], p[605];

void dfs2(int x) {
	for (int y : e[x]) {
		if (!cl[y]) {
			p[y] = x;	
			cl[y] = 3 - cl[x];
			dfs2(y);
		}
	}
}

void dfs3(int x, int p, int y, basic_string<int>& st, basic_string<int>& sol) {
	st += x;
	if (x == y) {
		sol = st;
	}

	for (int z : e[x]) {
		if (z == p)
			continue;
		dfs3(z, x, y, st, sol);
	}

	st.pop_back();
}

basic_string<int> tree_path(int x, int y) {
	basic_string<int> st, sol;
	dfs3(x, x, y, st, sol);
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	dfs1(1);
	cl[1] = 1;
	dfs2(1);

	basic_string<int> c[3];
	for (int i=1; i<=n; i++)
		c[cl[i]] += i;

	if (ask(c[1]) + ask(c[2]) == 0) {
		int k = c[1].size();
		cout << "Y " << k << '\n';
		for (int i=0; i<k; i++)
			cout << c[1][i] << " \n"[i == k-1];
		cout << flush;
	} else {
		for (int i=1; i<=n; i++) {
			basic_string<int> mg = c[cl[i]];
			mg.erase(find(mg.begin(), mg.end(), i));
			if (ask(mg + i) - ask(mg)) {
				int l = 1, r = mg.size(), o = -1;
				while (l <= r) {
					int m = (l+r) >> 1;
					auto sub = mg.substr(0, m);
					if (ask(sub + i) - ask(sub) == 0) {
						l = m + 1;							
					} else {
						o = m;
						r = m - 1;
					}
				}

				int v = mg[o-1];
				basic_string<int> ans = tree_path(i, v);
				int k = ans.size();
				cout << "N " << k << '\n';
				for (int i=0; i<k; i++)
					cout << ans[i] << " \n"[i == k-1];
				cout << flush;
				return 0;
			}
		}
	}
}