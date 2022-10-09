#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ld a[18][18];
int n;
ld p[1 << 18];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> a[i][j];

	p[(1 << n) - 1] = 1;

	for (int mask=(1<<n)-1; mask>0; mask--) {
		int bc = __builtin_popcount(mask);
		int bc2 = bc*(bc-1)/2;
		for (int i=0; i<n; i++) if (mask & (1 << i)) {
			for (int j=i+1; j<n; j++) if (mask & (1 << j)) {
				p[mask - (1 << i)] += p[mask] / bc2 * a[j][i];
				p[mask - (1 << j)] += p[mask] / bc2 * a[i][j];
			}
		}
	}

	for (int i=0; i<n; i++)
		cout << p[1 << i] << " \n"[i == n-1];
}