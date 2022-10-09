#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], z[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	z[1] = a[2] < a[1];
	for (int i=3; i<=n; i++) {
		int p = i-2;
		for (int k=1; k<n;) {
			int y = p / k, x;
			if (y == 0) {
				x = n;
			} else if (y == 1) {
				x = p + 1;
			} else {
				x = max(k, p / y - 1);
				while (p / x == y)
					x++;
			}
			if (a[i] < a[y+1])
				z[k]++, z[x]--;
			k = x;
		}
	}
	for (int i=1, t=0; i<n; i++)
		cout << (t += z[i]) << " \n"[i == n-1];
}