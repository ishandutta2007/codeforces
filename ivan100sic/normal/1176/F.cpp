#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int deset[1231];
int ostatak[1231];

void mx(ll& x, ll y) {
	x = max(x, y);
}

void resi(
	vector<ll>& nu,
	basic_string<pair<int, int>>& a,
	int j, int c, ll v, int mask = 0
) {
	if (c > 3)
		return;

	mx(nu[ostatak[j]], v);
	int n = a.size();
	for (int i=0; i<n; i++) {
		if ((mask & (1 << i)) == 0) {
			resi(nu, a, j+1, c+a[i].second, v+(a[i].first * deset[j+1]), mask | (1 << i));
		}
	}
}

void stress() {
	basic_string<pair<int, int>> zajedno = {{1, 1}, {2, 1}, {3, 1}, {4, 2}, {5, 3}};
	for (int n=0; n<200000; n++) {
		vector<ll> ol(10), nu(10);
		for (int i=0; i<10; i++)
			resi(nu, zajedno, i, 0, ol[i], 0);
		swap(ol, nu);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// stress();
	// return 0;

	for (int i=0; i<1231; i++) {
		deset[i] = i % 10 == 0 ? 2 : 1;
		ostatak[i] = i % 10;
	}

	vector<ll> ol(10);
	for (int i=1; i<10; i++)
		ol[i] = -123123123123123123ll;
	int n;
	cin >> n;
	while (n--) {
		int l;
		cin >> l;
		basic_string<int> niz[4];
		while (l--) {
			int x, y;
			cin >> x >> y;
			niz[x] += y;
		}
		for (int i=1; i<=3; i++)
			sort(niz[i].begin(), niz[i].end(), greater<int>());
		basic_string<pair<int, int>> zajedno;

		for (int i=0; i<min((int)niz[1].size(), 3); i++)
			zajedno += {niz[1][i], 1};

		if (niz[2].size())
			zajedno += {niz[2][0], 2};

		if (niz[3].size())
			zajedno += {niz[3][0], 3};

		vector<ll> nu(10, -123123123123123123ll);
		for (int i=0; i<10; i++)
			resi(nu, zajedno, i, 0, ol[i], 0);
		swap(ol, nu);
	}

	cout << *max_element(ol.begin(), ol.end()) << '\n';
}