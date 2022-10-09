#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, tgt;
int a[200005], t[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> tgt;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> t[i];

	ld ov = 0, un = 0;
	for (int i=0; i<n; i++) {
		if (t[i] > tgt)
			ov += (t[i] - tgt) * 1ll * a[i];
		else
			un += (tgt - t[i]) * 1ll * a[i];
	}

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int x, int y) {
		return abs(t[x] - tgt) < abs(t[y] - tgt);
	});

	ld mo = min(ov, un), sol = 0;
	ov = un = mo;
	for (int i : ord) {
		if (t[i] > tgt) {
			ld q = min(ld(a[i]), ov / (t[i] - tgt));
			ov -= q * (t[i] - tgt);
			sol += q;
		}
	}
	for (int i : ord) {
		if (t[i] < tgt) {
			ld q = min(ld(a[i]), un / (tgt - t[i]));
			un -= q * (tgt - t[i]);
			sol += q;
		}
	}
	for (int i : ord)
		if (t[i] == tgt)
			sol += a[i];
	cout << setprecision(20) << fixed << sol << '\n';
}