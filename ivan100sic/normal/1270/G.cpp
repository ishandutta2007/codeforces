#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int p[1000005], a[1000005];
int q[1000005], e[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			p[n-1-i] = a[i] + (n-i-1);
		}
		fill(q, q+n, -1);
		int x = 0, d = 0;
		while (q[x] == -1) {
			// cerr << "idem " << x << '\n';
			e[d] = x;
			q[x] = d++;
			x = p[x];
		}
		cout << d - q[x] << '\n';
		for (int i=q[x]; i<d; i++)
			cout << n-e[i] << ' ';
		cout << '\n';
	}
}