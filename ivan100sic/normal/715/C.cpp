#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// stvari oko drveta i centroida
int n;
basic_string<pair<int, int>> e[100005];
bool blok[100005];
int sz[100005], centroid;
ll sol;

void centroid_dfs1(int x, int p) {
	sz[x] = 1;
	for (auto [y, l] : e[x]) {
		if (y == p || blok[y])
			continue;
		centroid_dfs1(y, x);
		sz[x] += sz[y];
	}
}

void centroid_dfs2(int x, int p, int gsz) {
	bool ok = (gsz - sz[x])*2 <= gsz;
	for (auto [y, l] : e[x]) {
		if (y == p || blok[y])
			continue;
		centroid_dfs2(y, x, gsz);
		if (sz[y] * 2 > gsz)
			ok = false;
	}
	if (ok)
		centroid = x;
}

// stvari oko teorije brojeva
int M;
int p10[100005], pinv10[100005];

int inv(int x, int m) {
	ll z = 1;
	while (z % x)
		z += m;
	return z/x;
}

void precompute_nt() {
	p10[0] = pinv10[0] = 1;
	for (int i=1; i<100005; i++) {
		p10[i] = p10[i-1] * 10ll % M;
	}
	int z = inv(10, M);
	for (int i=1; i<100005; i++) {
		pinv10[i] = pinv10[i-1] * 1ll * z % M;
	}
}

void dfs_glavni(int x, int p, int vf, int vr, int dub,
	basic_string<pair<int, int>>& f, basic_string<int>& r)
{
	f += {vf, dub};
	r += vr;
	for (auto [y, l] : e[x]) {
		if (y == p || blok[y])
			continue;
		int wr = (vr + l*1ll*p10[dub]) % M;
		int wf = (10ll*vf + l) % M;
		dfs_glavni(y, x, wf, wr, dub+1, f, r);
	}
}

void spoji(basic_string<pair<int, int>>& f, basic_string<int>& r, int koef) {
	map<int, int> rc;
	for (int x : r)
		rc[x]++;
	for (auto [y, l] : f) {
		int x = pinv10[l] * 1ll * (M-y) % M;
		sol += koef * rc[x];
	}
}

void trivijalno(basic_string<pair<int, int>>& f, basic_string<int>& r) {
	for (auto [y, l] : f)
		if (y == 0)
			sol++;
	for (int x : r)
		if (x == 0)
			sol++;	
}

// glavni centroid
void resi(int x) {
	centroid_dfs1(x, x);
	centroid_dfs2(x, x, sz[x]);
	x = centroid;
	blok[x] = 1;

	basic_string<int> rs;
	basic_string<pair<int, int>> fs;
	for (auto [y, l] : e[x]) {
		if (blok[y])
			continue;
		basic_string<int> r;
		basic_string<pair<int, int>> f;
		dfs_glavni(y, x, l%M, l%M, 1, f, r);
		spoji(f, r, -1);
		trivijalno(f, r);
		rs += r;
		fs += f;
	}
	spoji(fs, rs, 1);
	for (auto [y, l] : e[x])
		if (!blok[y])
			resi(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> M;
	for (int i=1; i<n; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		e[u] += {v, l};
		e[v] += {u, l};
	}

	precompute_nt();
	resi(0);
	cout << sol << '\n';
}