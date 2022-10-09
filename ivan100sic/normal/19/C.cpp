#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M1 = 671834831;
const int M2 = 916758149;
const int B = 498132142;

typedef int niz[100005];

int n;
niz a, z1, z2, p1, p2, tmp, b;
basic_string<int> e[100005];
basic_string<pair<int, int>> preklapanja;

pair<int, int> get_hash(int l, int r) {
	int h1 = z1[r] - z1[l] * 1ll * p1[r-l] % M1;
	if (h1 < 0) h1 += M1;

	int h2 = z2[r] - z2[l] * 1ll * p2[r-l] % M2;
	if (h2 < 0) h2 += M2;

	return {h1, h2};
}

bool eq(int x, int y) {
	int z = y+y-x;
	if (z > n)
		return false;

	auto hx = get_hash(x, y);
	auto hy = get_hash(y, z);
	return hx == hy;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	int aw = a.second - a.first;
	int bw = b.second - b.first;
	if (aw != bw)
		return aw < bw;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	p1[0] = p2[0] = 1;
	for (int i=0; i<n; i++) {
		cin >> b[i];
		a[i] = b[i];
		tmp[i] = a[i];
	}
	sort(tmp, tmp+n);
	for (int i=0; i<n; i++) {
		a[i] = lower_bound(tmp, tmp+n, a[i]) - tmp + 1;
		e[a[i]] += i;
		z1[i+1] = (z1[i] * 1ll * B + a[i]) % M1;
		z2[i+1] = (z2[i] * 1ll * B + a[i]) % M2;
		p1[i+1] = p1[i] * 1ll * B % M1;
		p2[i+1] = p2[i] * 1ll * B % M2;
	}

	for (int i=1; i<=n; i++) {
		for (int j=0; j<(int)e[i].size(); j++) {
			for (int k=j+1; k<(int)e[i].size(); k++) {
				int x = e[i][j];
				int y = e[i][k];
				if (eq(x, y)) {
					preklapanja += {x, y};
				}
			}
		}
	}

	int reach = 0;
	sort(preklapanja.begin(), preklapanja.end(), cmp);
	for (auto [l, r] : preklapanja) {
		if (l < reach)
			continue;
		reach = r;
	}
	cout << n-reach << '\n';
	for (int i=reach; i<n; i++)
		cout << b[i] << " \n"[i == n];
}