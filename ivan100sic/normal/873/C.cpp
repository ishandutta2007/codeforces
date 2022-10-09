#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[105][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
		}
	}

	int skor = 0, rem = 0;

	for (int j=1; j<=m; j++) {
		int sko = 0;
		int rm = 0, kec = 0;
		for (int i=1; i<=n; i++) {
			if (a[i][j] == 1) {
				int sk = 0;
				for (int x=i; x<=i+k-1 && x <= n; x++) {
					if (a[x][j]) {
						sk++;
					}
				}
				if (sk > sko) {
					sko = sk;
					rm = kec;
				}
				kec++;
			}
		}
		skor += sko;
		rem += rm;
	}

	cout << skor << ' ' << rem << '\n';
}