#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll dp[50][3][50], n, t;
ll yy[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t;
	n++;
	for (ll i=0; i<45; i++)
		yy[i] = (n >> (44 - i)) & 1;
	dp[0][1][0] = 1;
	for (ll i=0; i<45; i++) {
		for (ll s=0; s<3; s++) {
			for (ll k=0; k<45; k++) {
				for (ll b=0; b<2; b++) {
					ll i1 = i+1;
					ll s1;
					if (s != 1)
						s1 = s;
					else {
						ll y = yy[i];
						if (b > y)
							s1 = 2;
						else if (b < y)
							s1 = 0;
						else
							s1 = 1;
					}
					ll k1 = k + b;
					dp[i1][s1][k1] += dp[i][s][k];
				}
			}
		}
	}

	ll z = 1, c = 1;
	while (z < t)
		z <<=1, c++;
	if (z != t) {
		cout << "0\n";
	} else {
		ll sol = dp[45][0][c] + dp[45][1][c];
		if (t == 1)
			sol -= 1;
		cout << sol << "\n";
	}
}