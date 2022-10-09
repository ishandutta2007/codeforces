#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct par {
	int p, q;
};

int n;
int nule;
int c[500005], d[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;

		int p=0, q=0;
		for (char x : s) {
			p += (x == '(' ? 1 : -1);
			q = min(q, p);
		}

		if (p == 0 && q == 0) {
			nule++;
		} else if (p > 0 && q == 0) {
			c[p]++;
		} else if (p < 0 && q == p) {
			d[-p]++;
		}
	}
	int sol = nule / 2;
	for (int i=0; i<500005; i++) {
		sol += min(c[i], d[i]);
	}
	cout << sol << '\n';
}