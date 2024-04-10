#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	string p, q;
	cin >> p >> q;

	ll c00 = 0, c01 = 0, c10 = 0, c11 = 0;

	for (int i=0; i<n; i++) {
		if (p[i] == '0' && q[i] == '0')
			c00++;
		else if (p[i] == '0' && q[i] == '1')
			c01++;
		else if (p[i] == '1' && q[i] == '0')
			c10++;
		else if (p[i] == '1' && q[i] == '1')
			c11++;
	}

	ll sol = c00*c11 + c10*c01 + c10*c00;

	cout << sol;
}