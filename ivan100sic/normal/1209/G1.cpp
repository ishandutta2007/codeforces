#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q, z;
int a[200005];
int b[200005];

void radd(int l, int r) {
	map<int, int> mp;
	int h = 0;
	for (int i=l; i<r; i++)
		h = max(h, ++mp[a[i]]);
	z += r-l - h;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=0; i<n; i++)
		cin >> a[i], b[a[i]] = i;

	int l = 0;
	while (l < n) {
		int r = l, q = b[a[l]];
		while (r <= q) {
			q = max(q, b[a[r]]);
			r++;
		}
		radd(l, r);
		l = r;
	}
	cout << z << '\n';
}