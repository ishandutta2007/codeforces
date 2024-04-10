#include <bits/stdc++.h>
using namespace std;

int n, m, k, q;
vector<int> e[100005];
int gdejeigracka[100005];

int dub[100005], sz[100005];
int velicina[100005];
bool rut[100005];
int uso[100005], izaso[100005];
int ttt = 0;

void dfs(int x, int d) {
	uso[x] = ++ttt;

	dub[x] = d;
	sz[x] = 1;
	for (int y : e[x]) {
		dfs(y, d+1);
		sz[x] += sz[y];
	}

	izaso[x] = ++ttt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> q;
	for (int i=1; i<=k; i++) {
		int dete, igracka;
		cin >> dete >> igracka;
		if (gdejeigracka[igracka]) {
			// e[dete].push_back(gdejeigracka[igracka]);
			e[gdejeigracka[igracka]].push_back(dete);
			// cerr << "grana " << dete << ' ' << gdejeigracka[igracka] << '\n';
			gdejeigracka[igracka] = dete;
		} else {
			gdejeigracka[igracka] = dete;
		}
	}

	//
	fill(dub+1, dub+n+1, -1);
	fill(rut+1, rut+n+1, true);

	for (int i=1; i<=n; i++) {
		for (int x : e[i]) {
			rut[x] = false;
		}
	}

	for (int i=1; i<=n; i++) {
		if (rut[i]) {
			// cerr << "rut " << i << '\n';
			dfs(i, 0);
		}
	}

	// cerr << "sz " << sz[12] << '\n';

	for (int i=1; i<=q; i++) {
		int dete, igracka, ans = -1;

		cin >> dete >> igracka;

		int balavac = gdejeigracka[igracka];

		//cerr << "upit " << dete << ' ' << balavac << '\n';

		if (balavac) {
			if (uso[dete] <= uso[balavac] && izaso[balavac] <= izaso[dete]) {
				ans = sz[dete];
			} else {
				ans = 0;
			}
		} else {
			ans = 0;
		}
		cout << ans << '\n';
	}


		


}