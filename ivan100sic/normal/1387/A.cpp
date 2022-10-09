// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
vector<pair<int, int>> e[100005];
bool vis[100005];
complex<int> c[100005];
int w[100005]; // 2x scaled
int finalsol[100005];

void dfs(int x, vector<int>& u) {
	u.push_back(x);
	vis[x] = 1;
	for (auto [y, s] : e[x]) {
		c[y] = complex<int>(s) - c[x];
		if (!vis[y]) {
			dfs(y, u);
		}
	}
}

void no() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		c += c;
		e[x].emplace_back(y, c);
		e[y].emplace_back(x, c);
	}

	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			vector<int> u;
			c[i] = {0, 1};
			dfs(i, u);

			// ajde da vidimo sta smo napravili
			int wparam = 0, wstate = -1;

			auto setwparam = [&](int w) {
				if (wstate == -1) {
					wparam = w;
					wstate = 0;
				} else if (wstate == 0) {
					if (w != wparam) {
						no();
					}
				}
			};

			for (int x : u) {
				for (auto [y, s] : e[x]) {
					// ovaj sused ima isti znak kao x, ogranici vrednost parametra
					if (c[x].imag() == c[y].imag()) {
						setwparam((s - c[x].real() - c[y].real()) / (c[x].imag() + c[y].imag()));
					} else {
						// samo proveri da li se uklapa
						if ((c[x] + c[y]).real() != s) {
							no();
						}
					}
				}
			}

			int wbest;

			if (wstate == -1) {
				vector<int> wvals;
				for (int x : u) {
					wvals.push_back(- c[x].real() * c[x].imag());
				}

				sort(begin(wvals), end(wvals));
				wbest = wvals[wvals.size() / 2];
			} else {
				wbest = wparam;
			}

			for (int x : u) {
				finalsol[x] = c[x].real() + c[x].imag() * wbest;
			}
		}
	}

	cout << setprecision(1) << fixed;

	cout << "YES\n";
	for (int i=1; i<=n; i++) {
		cout << finalsol[i]*0.5 << " \n"[i == n];
	}

}