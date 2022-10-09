#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int cena[1005], tip[1005];
basic_string<pair<int, int>> stolice, olovke;
basic_string<int> resenje[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		int c, t;
		cin >> c >> t;
		cena[i] = c;
		tip[i] = t;
		if (t == 1) {
			stolice += {c, i};
		} else {
			olovke += {c, i};
		}
	}

	sort(stolice.begin(), stolice.end());
	sort(olovke.begin(), olovke.end());

	if ((int)stolice.size() < k) {
		for (int i=0; i<(int)stolice.size(); i++) {
			resenje[i] += stolice[i].second;
		}
		for (int i=stolice.size(); i<(int)k; i++) {
			resenje[i] += olovke.back().second;
			olovke.pop_back();
		}
		for (auto [x, y] : olovke)
			resenje[k-1] += y;
	} else {
		reverse(stolice.begin(), stolice.end());
		for (int i=0; i<k-1; i++) {
			resenje[i] += stolice[i].second;
		}
		for (int i=k-1; i<(int)stolice.size(); i++) {
			resenje[k-1] += stolice[i].second;
		}
		for (auto [x, y] : olovke)
			resenje[k-1] += y;
	}

	ll z = 0;
	for (int i=0; i<k; i++) {
		int lo = 1123123123;
		bool ima = 0;
		for (int x : resenje[i]) {
			z += 2*cena[x];
			lo = min(lo, cena[x]);
			if (tip[x] == 1)
				ima = true;
		}
		if (ima)
			z -= lo;
	}
	cout << z/2 << "." << z%2*5 << '\n';
	for (int i=0; i<k; i++) {
		cout << resenje[i].size();
		for (int x : resenje[i])
			cout << ' ' << x;
		cout << '\n';
	}
}