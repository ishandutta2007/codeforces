#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int s[200005], p[11], q[11], r[11];
int ident;
int g[120][120];

int pton(int* p) {
	int x = 0;
	for (int i=0; i<k; i++) {
		int v = 0;
		for (int j=0; j<i; j++)
			v += p[i] > p[j];
		x = (i+1)*x + v;
	}
	return x;
}

struct stvar {
	bitset<120> a;
	int l, r;
};

unordered_map<bitset<120>, bitset<120>> cache;

void expand(bitset<120>& a, int b) {
	if (a[b])
		return;

	a[b] = 1;
	if (cache.count(a)) {
		a = cache[a];
		return;
	}

	auto& bb = cache[a];

	int q[120], qs=0, qe=0;
	q[qe++] = b;

	while (qs != qe) {
		int x = q[qs++];
		for (int y=0; y<120; y++) {
			if (a[y]) {
				int z = g[x][y];
				if (!a[z]) {
					q[qe++] = z;
					a[z] = 1;
				}
			}
		}
	}

	bb = a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;

	iota(q, q+k, 0);
	ident = pton(q);
	do {
		iota(p, p+k, 0);
		do {
			for (int i=0; i<k; i++)
				r[i] = p[q[i]];
			g[pton(p)][pton(q)] = pton(r);
		} while (next_permutation(p, p+k));
	} while (next_permutation(q, q+k));

	for (int i=0; i<n; i++) {
		for (int j=0; j<k; j++)
			cin >> p[j];
		s[i] = pton(p);
	}

	bitset<120> sid;
	sid[ident] = 1;

	vector<stvar> b;

	ll sol = 0;

	for (int i=0; i<n; i++) {
		for (auto& q : b)
			expand(q.a, s[i]);
		auto ja = sid;
		expand(ja, s[i]);
		b.push_back({ja, i, i});
		int j = 0;
		for (int k=1; k<(int)b.size(); k++) {
			if (b[k].a == b[j].a) {
				b[j].r = b[k].r;
			} else {
				b[++j] = b[k];
			}
		}
		b.resize(j+1);
		for (auto& q : b) {
			sol += (q.r-q.l+1) * q.a.count();
		}
	}

	cout << sol << '\n';
}