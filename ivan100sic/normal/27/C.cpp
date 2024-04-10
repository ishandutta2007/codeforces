#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
int fl[100005], fh[100005], bl[100005], bh[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	fl[1] = fh[1] = 1;
	for (int i=2; i<=n; i++) {
		fl[i] = a[i] < a[fl[i-1]] ? i : fl[i-1];
		fh[i] = a[i] > a[fh[i-1]] ? i : fh[i-1];
	}
	bl[n] = bh[n] = n;
	for (int i=n-1; i>=1; i--) {
		bl[i] = a[i] < a[bl[i+1]] ? i : bl[i+1];
		bh[i] = a[i] > a[bh[i+1]] ? i : bh[i+1];
	}

	for (int i=2; i<n; i++) {
		if (a[fl[i-1]] < a[i] && a[i] > a[bl[i+1]]) {
			cout << "3\n" << fl[i-1] << ' ' << i << ' ' << bl[i+1] << '\n';
			return 0;
		}
		if (a[fh[i-1]] > a[i] && a[i] < a[bh[i+1]]) {
			cout << "3\n" << fh[i-1] << ' ' << i << ' ' << bh[i+1] << '\n';
			return 0;
		}
	}

	cout << "0\n";
}