#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x, y, l, r;
int a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	l = 1;
	r = n;
	for (int i=1; i<=n; i++) {
		if (a[l] > a[r]) {
			(i%2 ? x : y) += a[l++];
		} else {
			(i%2 ? x : y) += a[r--];
		}
	}
	cout << x << ' ' << y << '\n';
}