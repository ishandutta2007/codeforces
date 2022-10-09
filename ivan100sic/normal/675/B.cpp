#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a, b, c, d;
int p, q, r, s;

bool ok(vector<int> a) {
	for (int x : a)
		if (x < 1 || x > n)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b >> c >> d;
	ll sol = 0;
	for (p=1; p<=n; p++) {
		q = b+p-c;
		r = a+p-d;
		s = r+b-c;
		if (ok({q, r, s}))
			sol += n;
	}
	cout << sol << '\n';

}