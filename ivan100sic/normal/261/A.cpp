#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int m, n;
int q[100005], a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m;
	for (int i=0; i<m; i++)
		cin >> q[i];
	sort(q, q+m);
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n, greater<int>());

	int k = 0, z = 0;
	int qi = q[0];
	while (k < n) {
		if (n-k <= qi) {
			while (k < n)
				z += a[k++];
		} else {
			for (int i=0; i<qi; i++)
				z += a[k++];
			k += 2;
		}
	}

	cout << z << '\n';
}