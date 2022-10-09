#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], parent[100005];
vector<int> e[100005];

ll dub_dole[100005], diam_dole[100005];
ll dub_gore[100005], diam_gore[100005];

void dfs_dole(int x, int p) {
	parent[x] = p;
	for (int y : e[x]) {
		if (y != p) {
			dfs_dole(y, x);
		}
	}

	vector<ll> v;

	for (int y : e[x]) {
		if (y != p) {
			v.push_back(dub_dole[y]);
			diam_dole[x] = max(diam_dole[x], diam_dole[y]);
		}
	}

	sort(v.begin(), v.end(), greater<ll>());
	if (v.size() == 0) {
		diam_dole[x] = a[x];
		dub_dole[x] = a[x];
	}
	else if (v.size() == 1) {
		diam_dole[x] = max(diam_dole[x], v[0] + a[x]);
		dub_dole[x] = v[0] + a[x];
	}
	else if (v.size() >= 2) {
		diam_dole[x] = max(diam_dole[x], v[0] + v[1] + a[x]);
		dub_dole[x] = v[0] + a[x];
	}
}

void dfs_gore(int x, int p) {

	multiset<ll> ms_dub, ms_diam;

	for (int y : e[x]) {
		if (y != p) {
			ms_dub.insert(dub_dole[y]);
			ms_diam.insert(diam_dole[y]);
		}
	}

	if (x != p) {
		ms_dub.insert(dub_gore[x]);
		ms_diam.insert(diam_gore[x]);
	}

	for (int y : e[x]) {
		if (y != p) {
			// prvo ukloni
			ms_dub.erase(ms_dub.find(dub_dole[y]));
			ms_diam.erase(ms_diam.find(diam_dole[y]));

			// racunaj dp diam
			if (ms_diam.size()) {
				diam_gore[y] = max(diam_gore[y], *ms_diam.rbegin());
			}

			if (ms_dub.size() == 1) {
				diam_gore[y] = max(diam_gore[y], a[x] + *ms_dub.rbegin());
			}
			else if (ms_dub.size() >= 2) {
				diam_gore[y] = max(diam_gore[y], a[x] + *ms_dub.rbegin() + *next(ms_dub.rbegin()));
			}
			else if (ms_dub.size() == 0) {
				diam_gore[y] = max(diam_gore[y], (ll)a[x]);
			}

			// racunaj dp dub
			if (ms_dub.size()) {
				dub_gore[y] = a[x] + *ms_dub.rbegin();
			}
			else {
				dub_gore[y] = a[x];
			}

			// vrati ono sto je bilo
			ms_dub.insert(dub_dole[y]);
			ms_diam.insert(diam_dole[y]);
		}
	}

	// ostalo

	for (int y : e[x]) {
		if (y != p) {
			dfs_gore(y, x);
		}
	}
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	dfs_dole(1, 1);
	dfs_gore(1, 1);
	
	/*
	for (int i = 1; i <= n; i++) {
		cerr << i << ' ' << diam_dole[i] << ' ' << diam_gore[i] << '\n';
	}
	*/
	
	// dva disjunktna
	ll sol = 0;
	for (int i = 2; i <= n; i++) {
		sol = max(sol, diam_gore[i] + diam_dole[i]);
	}

	sol = max(sol, diam_dole[1]);

	cout << sol << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}