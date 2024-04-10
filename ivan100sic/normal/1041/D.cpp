#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int l[200005], r[200005], h, n;
int reach[200005], prazno[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> h;
	int sol = 0;
	for (int i=1; i<=n; i++)
		cin >> l[i] >> r[i];

	reach[1] = 1;
	prazno[1] = 0;
	for (int i=1; i<=n; i++) {
		int& p = reach[i];
		if (i) {
			reach[i] = reach[i-1];
			prazno[i] = prazno[i-1] - (l[i] - r[i-1]);
		}
		while (1) {
			if (p == n)
				break;
			int e = l[p+1] - r[p];
			if (e + prazno[i] < h) {
				p++;
				prazno[i] += e;
			} else {
				break;
			}
		}
		// cerr << "reach " << i << ' ' << p << " prazno " << prazno[i] << '\n';
		sol = max(sol, r[reach[i]] + h - prazno[i] - l[i]);
	}
	sol = max(sol, h);
	cout << sol << '\n';
}