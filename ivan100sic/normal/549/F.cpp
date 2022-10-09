#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[300005], z[300005];
basic_string<int> e[1000005];
int l[300005], r[300005], p[300005];
int u[300005], v[300005];

void dfs(int x) {
	if (!x) return;
	dfs(l[x]);
	dfs(r[x]);
	u[x] = v[x] = x;
	if (l[x])
		u[x] = min(u[x], u[l[x]]);
	if (r[x])
		v[x] = max(v[x], v[r[x]]);
}

// koliko prefiksi niza a[l, r] imaju ostatak x
int prefiks_upit(int l, int r, int x) {
	x = ((x + z[l-1]) % k + k) % k;
	return upper_bound(e[x].begin(), e[x].end(), r)
		- lower_bound(e[x].begin(), e[x].end(), l-1);
}

// koliko sufiksa niza a[l, r] imaju ostatak x
int sufiks_upit(int l, int r, int x) {
	x = ((z[r] - x) % k + k) % k;
	return upper_bound(e[x].begin(), e[x].end(), r)
		- lower_bound(e[x].begin(), e[x].end(), l-1);
}

ll sol;

void resi(int x) {
	if (x - u[x] < v[x] - x) {
		// levo iteriram
		int z = 0;
		sol += prefiks_upit(x+1, v[x], z);

		for (int i=x-1; i>=u[x]; i--) {
			z = ((z - a[i]) % k + k) % k;
			sol += prefiks_upit(x+1, v[x], z);
		}
	} else {
		// desno iteriram
		int z = 0;
		sol += sufiks_upit(u[x], x-1, z);

		for (int i=x+1; i<=v[x]; i++) {
			z = ((z - a[i]) % k + k) % k;
			sol += sufiks_upit(u[x], x-1, z);
		}
	}
	if (r[x]) resi(r[x]);
	if (l[x]) resi(l[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		p[i] = i-1;
		r[i-1] = i;

		while (p[i] && a[i] > a[p[i]]) {
			int pp = p[i];
			int gp = p[pp];
			int lp = l[i];

			r[gp] = i;
			p[i] = gp;
			l[i] = pp;
			p[pp] = i;
			r[pp] = lp;
			if (lp)
				p[lp] = pp;
		}
	}

	e[0] += 0;
	for (int i=1; i<=n; i++) {
		z[i] = z[i-1] + a[i];
		z[i] %= k;
		e[z[i]] += i;
	}

	dfs(r[0]);
	resi(r[0]);

	cout << sol - n << '\n';
}