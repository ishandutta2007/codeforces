#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct plan {
	int l, r, c, p, id;
};

struct fw {
	vector<ll> cnt, sum;

	fw() : cnt(1048577, 0), sum(1048577, 0) {}

	void add(int i, int x) {
		for (int j = i; j<(1<<20); j+=j&-j) {
			cnt[j] += x;
			sum[j] += i*1ll*x;
		}
	}

	ll seek(ll c) {
		int i = 0;
		ll z = 0;
		for (int step=1<<19; step; step>>=1) {
			if (cnt[i + step] <= c) {
				z += sum[i + step];
				c -= cnt[i + step];
				i += step;
			}
		}
		z += min(c, cnt[i+1]) * (i+1ll);
		return z;
	}
} tree;

int n, k, m;
plan a[200005];
basic_string<int> pocetak[1000005], kraj[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> m;
	for (int i=1; i<=m; i++) {
		int l, r, c, p;
		cin >> l >> r >> c >> p;
		a[i] = {l, r, c, p, i};
		pocetak[l] += i;
		kraj[r+1] += i;
	}

	ll sol = 0;

	for (int i=1; i<=n; i++) {
		for (int j : pocetak[i])
			tree.add(a[j].p, a[j].c);
		for (int j : kraj[i])
			tree.add(a[j].p, -a[j].c);
		sol += tree.seek(k);
	}

	cout << sol << '\n';
}