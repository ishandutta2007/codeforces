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

const int nmax = 51;

int f[nmax][nmax];
int bin[nmax][nmax];
int fact[nmax];
int dp[nmax][nmax][nmax][nmax];
int sum2[nmax], sum3[nmax];

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	bin[0][0] = 1;
	for (int i = 1; i < nmax; ++i) {
		bin[i][0] = 1;
		for (int j = 1; j < nmax; ++j) {
			bin[i][j] = bin[i - 1][j];
			add(bin[i][j], bin[i - 1][j - 1]);
		}
	}

	fact[0] = 1;
	for (int i = 1; i < nmax; ++i) {
		fact[i] = fact[i - 1];
		mul(fact[i], i);
	}

	f[0][0] = 1;

	for (int a = 0; a < nmax; ++a) {
		if (a & 1) {
			continue;
		}
		for (int b = 0; b < nmax; ++b) {
			if (a) {
				int val = 0;
				val = f[a - 2][b];
				int pr = 1;
				for (int i = 1; i <= b; ++i) {
					mul(pr, b - i + 1);
					int x = pr;
					mul(x, f[a - 2][b - i]);
					add(val, x);
				}
				mul(val, a - 1);
				f[a][b] = val;
			} else {
				for (int i = 2; i < b; ++i) {
					int val = bin[b - 1][i];
					mul(val, fact[i]);
					mul(val, r2);
					mul(val, f[a][b - i - 1]);
					add(f[a][b], val);
				}
			}
		}
	}

	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}

	int cnt1 = 0, cnt2 = 0;
	if (d[0] == 3 && n < 4) {
		cout << "0\n";
		return 0;
	}

	if (d[0] == 2) {
		sum2[0] = 1;
	} else {
		sum3[0] = 1;
	}
	for (int i = 1; i < n; ++i) {
		sum2[i] = sum2[i - 1];
		sum3[i] = sum3[i - 1];
		if (d[i] == 2) {
			++sum2[i];
		} else {
			++sum3[i];
		}
	}

	for (int i = 1; i <= d[0]; ++i) {
		if (d[i] == 2) {
			++cnt1;
		} else {
			++cnt2;
		}
	}

	dp[1 + d[0]][d[0]][cnt1][cnt2] = 1;

	for (int put = 1 + d[0]; put <= n; ++put) {
		for (int last = 1; last <= put; ++last) {
			for (cnt2 = 0; cnt2 <= last; ++cnt2) {
				for (cnt1 = 0; cnt1 + cnt2 <= last; ++cnt1) {
					if (!dp[put][last][cnt1][cnt2]) {
						continue;
					}

					for (int a = 0; a <= cnt1; ++a) {
						for (int b = 0; b <= cnt2; ++b) {
							for (int c = 0; b + c <= cnt2; ++c) {
								if (a + b + c == 0) {
									continue;
								}
								int val = bin[cnt1][a];
								mul(val, bin[cnt2][b]);
								mul(val, bin[cnt2 - b][c]);
								mul(val, f[a + b][c]);
								mul(val, dp[put][last][cnt1][cnt2]);
								/*if (put == 3 && last == 2 && val) {
									cout << "!" << put << " " << last << " " << cnt1 << " " << cnt2 << " " << a << " " << b << " " << c << "\n";
								}*/
								add(dp[put][last][cnt1 - a + b][cnt2 - b - c], val);
							}
						}
					}
				}
			}

			for (cnt1 = 0; cnt1 <= last; ++cnt1) {
				for (cnt2 = 0; cnt1 + cnt2 <= last; ++cnt2) {
					if (!dp[put][last][cnt1][cnt2]) {
						continue;
					}

					int nx = cnt1 + 2 * cnt2;
					if (put + nx > n) {
						continue;
					}

					int val = dp[put][last][cnt1][cnt2];
					for (int i = 0; i < cnt1; ++i) {
						mul(val, nx - i);
					}
					for (int i = 0; i < cnt2; ++i) {
						mul(val, bin[nx - cnt1 - 2 * i][2]);
					}

					int a = sum2[nx + put - 1] - sum2[put - 1];
					int b = sum3[nx + put - 1] - sum3[put - 1];
					add(dp[put + nx][nx][a][b], val);
				}
			}
		}
	}

	int ans = 0;
	for (int last = 1; last <= n; ++last) {
		add(ans, dp[n][last][0][0]);
	}
	cout << ans << "\n";

}