#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[1005];
int p, q, hit;
bool u[1005], v[1005];

void dfs(int x, int parent) {
	if (u[x]) {
		hit = x;
		return;
	}

	for (int y : e[x]) {
		if (y != parent) {
			dfs(y, x);
		}
	}
}

int ask_inv(int x) {
	cout << "B " << x << '\n' << flush;
	cin >> x;
	return x;
}

int ask(int x) {
	cout << "A " << x << '\n' << flush;
	cin >> x;
	return x;
}

void ans(int x) {
	cout << "C " << x << '\n' << flush;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n; i++)
			e[i].clear();
		for (int i=1; i<n; i++) {
			int u, v;
			cin >> u >> v;
			e[u] += v;
			e[v] += u;
		}
		fill(u, u+n+1, 0);
		fill(v, v+n+1, 0);
		cin >> p;
		for (int i=0; i<p; i++) {
			int x;
			cin >> x;
			u[x] = 1;
		}
		cin >> q;
		for (int i=0; i<q; i++) {
			int x;
			cin >> x;
			v[x] = 1;
		}

		int r2 = find(v, v+n+1, true) - v;

		int r1 = ask_inv(r2);

		if (u[r1]) {
			ans(r1);
		} else {
			dfs(r1, r1);
			int hit2 = ask(hit);
			if (v[hit2]) {
				ans(hit);
			} else {
				ans(-1);
			}
		}
	}
}