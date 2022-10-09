#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int H = 41;

void mn(ll& x, ll y) {
	x = min(x, y);
}

struct mat {
	ll a[H][H];

	mat() {
		memset(a, 63, sizeof a);
	}

	mat operator* (const mat& b) const {
		mat t;
		for (int i=0; i<H; i++) {
			for (int j=0; j<H; j++) {
				for (int k=0; k<H; k++) {
					mn(t.a[i][k], a[i][j] + b.a[j][k]); 
				}
			}
		}
		return t;
	}
};

mat pw(mat a, int b) {
	if (b == 1)
		return a;
	mat c = pw(a, b >> 1);
	c = c*c;
	if (b & 1)
		c = c*a;
	return c;
}

int n, m;
int a[20], b[20];
ll dp[H][21][H];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	memset(dp, 63, sizeof dp);
	for (int i=0; i<=40; i++) {
		dp[i][0][i] = 0;
		for (int j=0; j<n; j++) {
			for (int k=0; k<H; k++) {
				if (k < H-1) {
					mn(dp[i][j+1][k+1], dp[i][j][k] + a[j]);
				}
				if (k > 0) {
					mn(dp[i][j+1][k-1], dp[i][j][k] + b[j]);
				}
			}
		}
	}

	mat t;
	for (int i=0; i<H; i++)
		for (int j=0; j<H; j++)
			t.a[i][j] = dp[i][n][j];
	cout << pw(t, m).a[0][0] << '\n';
}