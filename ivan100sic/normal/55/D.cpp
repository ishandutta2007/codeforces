#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int lcm(int x, int y) {
	return x*y / gcd(x, y);
}

int lv[1024]; // ima ih 48
int lt[48][10];

void find_lcmtable() {
	int k = 0;
	for (int mask=2; mask<(1<<10); mask+=2) {
		int l = 1;
		for (int i=1; i<10; i++) {
			if (mask & (1 << i)) {
				l = lcm(l, i);
			}
		}
		lv[k++] = l;
	}
	sort(lv, lv + k);
	unique(lv, lv + k);
	for (int i=0; i<48; i++) {
		for (int j=0; j<10; j++) {
			if (j == 0)
				lt[i][j] = i;
			else
				lt[i][j] = lower_bound(lv, lv+48, lcm(lv[i], j)) - lv;
		}
	}
}

int a[19];
ll dp[20][2][48][2520];

// dobrih brojeva manjih od x
ll count(ll x) {
	for (int i=18; i>=0; i--) {
		a[i] = x % 10;
		x /= 10;
	}

	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0] = 1;
	for (int i=0; i<19; i++) {
		for (int j=0; j<2; j++) {
			for (int k=0; k<48; k++) {
				for (int l=0; l<2520; l++) {
					for (int x=0; x<10; x++) {
						if (j == 0 && x > a[i])
							break;
						if (dp[i][j][k][l] == 0)
							continue;
						int i1 = i+1;
						int j1 = j == 1 || x < a[i];
						int k1 = lt[k][x];
						int l1 = (10*l + x) % 2520;

						// cerr << i << "," << j << "," << k << "," << l << " -> ";
						// cerr << i1 << "," << j1 << "," << k1 << "," << l1 << "\n";

						dp[i1][j1][k1][l1] += dp[i][j][k][l];
					}
				}
			}
		}
	}

	ll sol = 0;
	for (int i=0; i<48; i++) {
		for (int j=0; j<2520; j+=lv[i]) {
			sol += dp[19][1][i][j];
		}
	}

	// cerr << sol << '\n';

	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	find_lcmtable();

	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		cout << count(b+1) - count(a) << '\n';
	}
}