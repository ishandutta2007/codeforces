#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[300005];
int c[1000005], z[1000005];

inline int sum(int l, int r) {
	if (l > r || l > 1000000) return 0;
	return z[min(1000000, r)] - z[max(0, l-1)];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}
	for (int i=1; i<=1000000; i++)
		z[i] = z[i-1] + c[i];

	for (int d=1000000; d>=1; d--) {
		int br = 0;
		for (int x=d; x<=2000000; x+=d) {
			br += sum(x, x + min(d-1, k));
		}
		if (br == n) {
			cout << d << '\n';
			return 0;
		}
	}
}