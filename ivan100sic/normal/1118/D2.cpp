#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[200005];

bool moze(int t, int sol) {
	int ok = 1;
	for (int i=0; i<t; i++)
		if (a[i] - i/sol <= 0) {
			ok = 0;
			break;
		}
	return ok;
}

bool moze(int sol) {
	int l=1, r=n, o=-1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (moze(m, sol)) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	ll z = 0;
	for (int i=0; i<o; i++)
		z += a[i] - i/sol;

	return z >= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n, greater<int>());
	int l=1, r=n, o=-1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << o << '\n';
}