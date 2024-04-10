#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s;
int r[5000005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	
	ull f = 0, b = 0, p = 1;

	for (int i=1; i<=n; i++) {
		f += s[i-1] * p;
		b = 555 * b + s[i-1];
		p *= 555;
		if (f == b) {
			r[i] = r[i >> 1] + 1;
		}
	}

	cout << accumulate(r, r+n+1, 0) << '\n';
}