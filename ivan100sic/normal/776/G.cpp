// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll fh(string s) {
	ll x = 0;
	for (char c : s) {
		if (isdigit(c)) {
			x = 16*x + c - 48;
		} else {
			x = 16*x + c - 'a' + 10;
		}
	}
	return x;
}

bool jeste(ll x) {
	ll dm = 0;
	for (int i=0; i<15; i++) {
		ll d = (x >> (4*i)) & 15;
		dm = max(dm, d);
	}
	return x & (1ll << dm);
}

ll resi_brut(ll x) {
	ll z = 0;
	for (ll i=1; i<x; i++) {
		if (jeste(i)) {
			z++;
		}
	}
	return z;
}

int nl;
int a[16];
//    broj stavljenih cifara
//        da li se ceo prefiks poklapa
//           da li smo stavili max cifru
ll dp[17][2][2];

void xtr(ll x) {
	nl = 0;
	while (x) {
		a[nl++] = x & 15;
		x >>= 4;
	}
	reverse(a, a+nl);
}

ll resi(ll x) {
	xtr(x);
	ll z = 0;

	// m = najveca cifra
	for (int m=1; m<=15; m++) {
		memset(dp, 0, sizeof dp);
		dp[0][1][0] = 1;

		int cri = nl-1-m/4;
		int crj = m%4;
		// bit crj u cifri sa rednim brojem cri ne sme da bude 1

		for (int i=0; i<nl; i++) {
			for (int p : {0, 1}) {
				for (int h : {0, 1}) {
					// stavljamo cifru y
					for (int y=0; y<=m; y++) {
						if (p && y > a[i]) break;
						if (i == cri && (y & (1 << crj))) continue;
						int p2 = p && (y == a[i]);
						int h2 = h || (y == m);
						dp[i+1][p2][h2] += dp[i][p][h];
					}
				}
			}
		}

		z += dp[nl][0][1];
	}

	// cerr << "resi " << x << " -> " << z << '\n';
	return x - z;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		string hl, hr;
		cin >> hl >> hr;
		cout << resi(fh(hr)+1) - resi(fh(hl)) - (hl == "0") << '\n';
	}
}