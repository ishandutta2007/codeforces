#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];
int b[200005];
int nx[200005];

int e(int x) {
	if (x > n) return x;
	if (a[x] == b[x]) {
		return nx[x] = e(nx[x]);
	} else {
		return x;
	}
}

void sipuj(int p, int x) {
	if (!x || p > n) return;
	int y = min(a[p] - b[p], x);
	b[p] += y;
	x -= y;
	sipuj(e(p), x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<=n; i++)
		nx[i] = i+1;

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int p, x;
			cin >> p >> x;
			sipuj(p, x);
		} else {
			int x;
			cin >> x;
			cout << b[x] << '\n';
		}
	}
}