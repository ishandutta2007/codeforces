#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[1005];
ld b[1005][1005], sol;

int l[1005], r[1005];

void run() {
	for (int i=0; i<m; i++) {
		int l = ::l[i], r = ::r[i];
		for (int j=1; j<=n; j++) {
			if (j != l && j != r) {
				b[j][l] = b[j][r] = (b[j][l] + b[j][r]) / 2;
				b[l][j] = b[r][j] = (b[l][j] + b[r][j]) / 2;
			}
		}
		b[l][r] = b[r][l] = (b[l][r] + b[r][l]) / 2;
		b[l][l] = b[r][r] = (b[l][l] + b[r][r]) / 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++)
		cin >> l[i] >> r[i];

	memset(b, 0, sizeof b);
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (a[i] < a[j])
				b[i][j] = 1;
	run();
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			sol += b[j][i];

	memset(b, 0, sizeof b);
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (a[i] > a[j])
				b[i][j] = 1;
	run();
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			sol += b[i][j];

	cout << setprecision(20) << fixed << sol << '\n';
}