#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

string s;
int n;

int l[200005], r[200005];

int f[400005];
int finv[400005];

const int MOD = 1'000'000'007;

int pw(int a, int b) {
	if (b == 0) {
		return 1;
	}

	int t = pw(a, b/2);
	t = t * 1ll * t % MOD;
	if (b % 2) {
		t = t * 1ll * a % MOD;
	}
	return t;
}

int inv(int x) {
	return pw(x, MOD-2);
}

void init() {
	f[0] = 1;
	finv[0] = 1;
	for (int i=1; i<400005; i++) {
		f[i] = f[i-1] * 1ll * i % MOD;
		finv[i] = inv(f[i]);
	}
}

int bk(int a, int b) {
	return f[a+b] * 1ll * finv[a] % MOD * finv[b] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	init();

	cin >> s;
	n = s.size();
	s = string(" ") + s;

	l[0] = 0;
	for (int i=1; i<=n; i++) {
		l[i] = l[i-1] + (s[i] == '(' ? 1 : 0);
	}

	r[n+1] = 0;
	for (int i=n; i>=1; i--) {
		r[i] = r[i+1] + (s[i] == ')' ? 1 : 0);
	}

	int sol = 0;

	for (int i=1; i<n; i++) {
		int a = l[i];
		int b = r[i+1];

		if (s[i] == '(') {

			// cerr << a << ' ' << b << ' ' << bk(a, b-1) << '\n';

			sol += bk(a, b-1);
			if (sol >= MOD) {
				sol -= MOD;
			}
		}
	}

	cout << sol;
}