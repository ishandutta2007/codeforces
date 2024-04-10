#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[300005][8];

int fi, fj;

int pos[256];

bool moze(int v) {
	memset(pos, 0xff, sizeof pos);
	for (int i=0; i<n; i++) {
		int mask = 0;
		for (int j=0; j<m; j++) {
			if (a[i][j] >= v) {
				mask += 1 << j;
			}
		}
		pos[mask] = i;
	}
	for (int i=0; i<(1<<m); i++) {
		for (int j=0; j<(1<<m); j++) {
			if ((i | j) == (1 << m) - 1 && pos[i] != -1 && pos[j] != -1) {
				fi = pos[i];
				fj = pos[j];
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];

	int l = 0, r = 1e9, oi = 1, oj = 1;
	while (l <= r) {
		int mid = (l+r) >> 1;
		if (moze(mid)) {
			oi = fi + 1;
			oj = fj + 1;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << oi << ' ' << oj << '\n';
}