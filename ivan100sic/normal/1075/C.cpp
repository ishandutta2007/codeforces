#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	int k = 0;
	for (int i=0; i<m; i++) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if (x1 == 1) {
			b[k++] = x2;
		}
	}
	sort(b, b+k);
	// ne brisem nijednu vertikalu
	a[n] = 1000000000;
	int sol = b+k - lower_bound(b, b+k, a[0]);;
	for (int i=0; i<n; i++) {
		int v = i+1;
		v += b+k - lower_bound(b, b+k, a[i+1]);
		sol = min(sol, v);
	}
	cout << sol << '\n';
}