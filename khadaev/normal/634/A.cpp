#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	int ja, jb;
	--n;
	forn(i, 0, n) {
		cin >> a[i];
		if (a[i] == 1) ja = i;
		if (a[i] == 0) --i;
	}
	forn(i, 0, n) {
		cin >> b[i];
		if (b[i] == 1) jb = i;
		if (b[i] == 0) --i;
	}
	forn(i, 0, n)
		if (a[(ja + i) % n] != b[(jb + i) % n]) {
			cout << "NO\n";
			return 0;
		} 
	cout << "YES\n";

	return 0;
}