#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int q, n, a[105];
bool u[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> q;
	while (q--) {
		cin >> n;
		memset(u, 0, sizeof u);
		for (int i=1; i<=n; i++)
			cin >> a[i];
		for (int i=1; i<=n; i++) {
			int j = find(a+1, a+n+1, i) - a;
			while (j > 1 && !u[j-1] && a[j-1] > a[j])
				u[j-1] = 1, swap(a[j-1], a[j]), j--;
		}
		for (int i=1; i<=n; i++)
			cout << a[i] << " \n"[i == n];
	}
}