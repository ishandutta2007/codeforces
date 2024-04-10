#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s, a, b;
ull z[2005], pw[2005];
basic_string<int> p, q;

ull sol[4000005];
int rr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pw[0] = 1;
	for (int i=1; i<2005; i++)
		pw[i] = pw[i-1] * 12321;

	cin >> s >> a >> b;
	n = s.size();
	for (int i=0; i<n; i++) {
		if (s.substr(i, a.size()) == a) {
			p += i;
		}
		if (s.substr(i, b.size()) == b) {
			q += i + b.size();
		}
		z[i+1] = z[i] * 12321 + s[i];
	}

	for (int i : p) {
		for (int j : q) {
			if (j-i >= (int)max(a.size(), b.size()))
				sol[rr++] += (z[j] - z[i] * pw[j-i]);
		}
	}

	sort(sol, sol+rr);
	cout << (unique(sol, sol+rr) - sol) << '\n';
}