#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int r2 = (mod + 1) / 2;

void add(int& a, int b)
{
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void sub(int& a, int b)
{
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

void mul(int& a, int b)
{
	ll c = ll(a) * ll(b);
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

int sumy[10][10][10][10][10][10];
int sumy2[10][10][10][10][10][10];
int sum1[10][10][10][10][10][10];

void update(int x1, int x2, int x3, int x4, int x5, int x6, int y)
{
	int y2 = y;
	mul(y2, y);
	for (int i1 = x1; i1 >= 0; i1 = (i1 & (i1 + 1)) - 1) {
		for (int i2 = x2; i2 >= 0; i2 = (i2 & (i2 + 1)) - 1) {
			for (int i3 = x3; i3 >= 0; i3 = (i3 & (i3 + 1)) - 1) {
				for (int i4 = x4; i4 >= 0; i4 = (i4 & (i4 + 1)) - 1) {
					for (int i5 = x5; i5 >= 0; i5 = (i5 & (i5 + 1)) - 1) {
						for (int i6 = x6; i6 >= 0; i6 = (i6 & (i6 + 1)) - 1) {
							add(sumy[i1][i2][i3][i4][i5][i6], y);
							add(sumy2[i1][i2][i3][i4][i5][i6], y2);
							add(sum1[i1][i2][i3][i4][i5][i6], 1);
						}
					}
				}
			}
		}
	}
}

void get(int x1, int x2, int x3, int x4, int x5, int x6, int& s, int& y, int& y2)
{
	s = 0, y = 0, y2 = 0;
	for (int i1 = x1; i1 < 10; i1 = (i1 | (i1 + 1))) {
		for (int i2 = x2; i2 < 10; i2 = (i2 | (i2 + 1))) {
			for (int i3 = x3; i3 < 10; i3 = (i3 | (i3 + 1))) {
				for (int i4 = x4; i4 < 10; i4 = (i4 | (i4 + 1))) {
					for (int i5 = x5; i5 < 10; i5 = (i5 | (i5 + 1))) {
						for (int i6 = x6; i6 < 10; i6 = (i6 | (i6 + 1))) {
							add(y, sumy[i1][i2][i3][i4][i5][i6]);
							add(y2, sumy2[i1][i2][i3][i4][i5][i6]);
							add(s, sum1[i1][i2][i3][i4][i5][i6]);
						}
					}
				}
			}
		}
	}
}

const int nmax = 1e6;

void split(int y, int& x1, int& x2, int& x3, int& x4, int& x5, int& x6)
{
	x6 = y % 10;
	y /= 10;

	x5 = y % 10;
	y /= 10;

	x4 = y % 10;
	y /= 10;

	x3 = y % 10;
	y /= 10;

	x2 = y % 10;
	y /= 10;

	x1 = y % 10;
	y /= 10;
}

int y[nmax];
int h[10][10][10][10][10][10];
int deg2[nmax];

bool bit(int mask, int pos)
{
	return (mask >> pos) & 1;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	//freopen("input.txt", "r", stdin);

    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/

	deg2[0] = 1;
	for (int i = 1; i < nmax; ++i) {
		deg2[i] = deg2[i - 1];
		mul(deg2[i], 2);
	}

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &y[i]);
	}

	for (int i = 0; i < n; ++i) {
		int x1, x2, x3, x4, x5, x6;
		split(y[i], x1, x2, x3, x4, x5, x6);
		//cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << " " << x6 << "\n";
		update(x1, x2, x3, x4, x5, x6, y[i]);
	}

	set<int> ss;

	for (int x = 0; x < nmax; ++x) {
		int sy, s, sy2;
		int x1, x2, x3, x4, x5, x6;
		split(x, x1, x2, x3, x4, x5, x6);
		get(x1, x2, x3, x4, x5, x6, s, sy, sy2);
		//cout << "!" << sy << " " << s << " " << sy2 << "\n";
		int ans = sy;
		mul(ans, sy);
		sub(ans, sy2);
		mul(ans, r2);
		add(ans, sy2);
		mul(ans, deg2[s - 1]);
		h[x1][x2][x3][x4][x5][x6] = ans;
		/*if (x == 999999) {
			cout << sy << " " << s << " " << sy2 << "\n";
		}*/
	}

	//cout << h[9][9][9][9][9][9] << "\n";

	ll total = 0;

	for (int x = 0; x < nmax; ++x) {
		int x1, x2, x3, x4, x5, x6;
		split(x, x1, x2, x3, x4, x5, x6);
		int curr = 0;
		for (int mask = 0; mask < (1 << 6); ++mask) {
			int z[7];
			int c = 0;
			for (int b = 0; b < 6; ++b) {
				if (bit(mask, b)) {
					++c;
					z[b + 1] = 1;
				} else {
					z[b + 1] = 0;
				}
			}
			if (x1 + z[1] < 10 && x2 + z[2] < 10 && x3 + z[3] < 10 && x4 + z[4] < 10 && x5 + z[5] < 10 && x6 + z[6] < 10) {
				int sum = h[x1 + z[1]][x2 + z[2]][x3 + z[3]][x4 + z[4]][x5 + z[5]][x6 + z[6]];
				if (c & 1) {
					sub(curr, sum);
				} else {
					add(curr, sum);
				}
			}
		}
		ll res = ll(curr) * ll(x);
		/*if (curr) {
			cout << x << " " << curr << "\n";
		}*/
		total ^= res;
	}

	printf("%lld\n", total);

}