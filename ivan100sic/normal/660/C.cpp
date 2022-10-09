#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[300005], z[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		z[i+1] = z[i] + (1 - a[i]);
	}
	int r = 0, s = -1, j = -1, u = -1;
	for (int l=0; l<n; l++) {
		while (r < n && z[r+1] - z[l] <= k)
			r++;
		if (r-l > s) {
			s = r-l;
			j = l;
			u = r;
		}
	}
	fill(a+j, a+u, 1);
	cout << s << '\n';
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}