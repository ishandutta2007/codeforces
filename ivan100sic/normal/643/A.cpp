// my code from vjudge
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[5005];
int b[5005], c[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=n; i++) {
		int mx = 0, idx = 0;
		fill(b, b+n+1, 0);
		for (int j=i; j<=n; j++) {
			int x = a[j];
			b[x]++;
			if (b[x] == mx) {
				idx = min(idx, x);
			} else if (b[x] > mx) {
				mx = b[x];
				idx = x;
			}
			c[idx]++;
		}
	}

	for (int i=1; i<=n; i++)
		cout << c[i] << ' ';
	cout << '\n';
}