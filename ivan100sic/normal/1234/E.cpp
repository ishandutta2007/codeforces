#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[200005];
ll z[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> a[i];
	}

	for (int i=2; i<=m; i++) {
		int x = a[i-1];
		int y = a[i];

		if (x > y)
			swap(x, y);
		if (x == y)
			continue;

		z[1] += y-x;
		z[x] += x-1;
		z[x+1] -= x;
		z[y] -= y-x-1;
		z[y] += x;
		z[y+1] += y-2*x;
	}

	for (int i=1; i<=n; i++)
		cout << (z[i] += z[i-1]) << " \n"[i == n];
}