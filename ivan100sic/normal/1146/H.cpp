#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	bool operator< (const pt& b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

struct radial {
	pt b;

	bool operator() (pt a, pt c) {
		return det(b, a, c) < 0;
	}
};

int n;
pt a[305], b[305];
ll dp[4][305][305];
ll z;

ll daj_dp(pt baza, int n) {
	b[0] = baza;
	sort(b+1, b+n+1, radial{baza});
	memset(dp, 0, sizeof(dp));
	for (int i=1; i<=n; i++) {
		dp[0][0][i] = 1;
	}
	for (int t=0; t<3; t++) {
		for (int i=0; i<=n; i++) {
			for (int j=i+1; j<=n; j++) {
				if (!dp[t][i][j])
					continue;
				for (int k=j+1; k<=n; k++) {
					if (det(b[i], b[j], b[k]) < 0)
						dp[t+1][j][k] += dp[t][i][j];
				}
			}
		}
	}
	ll z = 0;
	for (int i=0; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			z += dp[3][i][j];
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
	}

	sort(a, a+n);
	ll z = 0;
	for (int i=0; i<n; i++) {
		copy(a+i+1, a+n, b+1);
		z += daj_dp(a[i], n-i-1);
	}

	cout << z << '\n';
}