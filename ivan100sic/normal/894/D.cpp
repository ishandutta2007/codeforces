#include <bits/stdc++.h>
using namespace std;

int n, q;
int e[1000005];
int dub[1000005];

int vals[1000005];

int t;
int l[1000005], r[1000005];

void dfs(int x) {
	l[x] = ++t;

	int y = 2*x;
	int z = 2*x+1;

	if (y <= n) {
		dub[y] = dub[x] + e[y];
		dfs(y);
	}

	if (z <= n) {
		dub[z] = dub[x] + e[z];
		dfs(z);
	}

	r[x] = t;
}

vector<int> a[2200005];
vector<long long> pz[2200005];

void napravi(const int x) {
	if (x > n) {
		return;
	}

	const int y = 2*x;
	const int z = y + 1;

	napravi(y);
	napravi(z);

	a[x].push_back(dub[x]);
	merge(a[y].begin(), a[y].end(), a[z].begin(), a[z].end(), back_inserter(a[x]));

	pz[x].resize(a[x].size() + 1);
	pz[x][0] = 0;
	for (size_t i=0; i<a[x].size(); i++) {
		pz[x][i+1] = pz[x][i] + a[x][i];
	}
}

int aq[100005], hq[100005];
vector<int> attach[1000005];

long long gggg(int x, int h) {
	if (h <= 0) {
		return 0;
	}
	int broj = lower_bound(a[x].begin(), a[x].end(), h) - a[x].begin();
	return h * 1ll * broj - pz[x][broj];
}

long long outp[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=2; i<=n; i++) {
		cin >> e[i];
	}

	for (int i=1; i<=n; i++) {
		vals[l[i]] = dub[i];
	}

	for (int i=1; i<=q; i++) {
		cin >> aq[i] >> hq[i];
		attach[aq[i]].push_back(i);
	}

	dfs(1);
	napravi(1);

	/*
	for (int i=1; i<=n; i++) {
		cerr << i << ' ' << dub[i] << ' ' << l[i] << ' ' << r[i] << '\n';
	}
	*/

	for (int i=1; i<=n; i++) {
		if (attach[i].size()) {

			for (int qid : attach[i]) {
				int h = hq[qid];

				int target = h + dub[i];
				long long ans = gggg(i, target);				

				int x = i;
				while (x > 1) {
					int p = x >> 1;
					ans += gggg(p, target - 2*e[x]);
					ans -= gggg(x, target - 2*e[x]);
					target -= 2*e[x];
					x = p;
				}

				outp[qid] = ans;
			}
			
		}
	}

	for (int i=1; i<=q; i++) {
		cout << outp[i] << '\n';
	}


}