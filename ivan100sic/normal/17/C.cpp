#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

static const int M = 51123987;
static int dp[2][155][155][155][4], n;
static string s;

static inline void ad(int& x, int y) {
	x += y;
	if (x >= M)
		x -= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	dp[0][0][0][0][3] = 1;
	string p = s;
	int nuq = unique(p.begin(), p.end()) - p.begin();
	int nn = n/3 + 3;

	// ovo pada na vreme ali ok, igramo se
	for (int k=0; k<nuq; k++) {
		auto cr = dp[k%2];
		auto nx = dp[1-k%2];
		memset(nx, 0, sizeof(dp[0]));

		int y = p[k] - 'a';
		int da=0, db=0, dc=0;
		if (y == 0)
			da = 1;
		else if (y == 1)
			db = 1;
		else if (y == 2)
			dc = 1;

		for (int a=0; a<=n && a <= nn; a++) {
			for (int b=0; a+b<=n && b <= nn; b++) {
				for (int c=0; a+b+c<=n && c <= nn; c++) {
					for (int x=0; x<4; x++) {
						int crv = cr[a][b][c][x];
						if (!crv)
							continue;
						if (x != y) {
							ad(nx[a][b][c][x], crv);
							ad(nx[a+da][b+db][c+dc][x], M-crv);

							int w = n-a-b-c+1;
							ad(nx[a+da][b+db][c+dc][y], crv);
							ad(nx[a+da*w][b+db*w][c+dc*w][y], M-crv);
						}
					}
				}
			}
		}

		for (int a=0; a<=n && a <= nn; a++) {
			for (int b=0; a+b<=n && b <= nn; b++) {
				for (int c=0; a+b+c<=n && c <= nn; c++) {
					for (int x=0; x<4; x++) {
						ad(nx[a+da][b+db][c+dc][x], nx[a][b][c][x]);
					}
				}
			}
		}
	}

	int z = 0;
	for (int a=0; a<=n; a++) {
		for (int b=0; a+b<=n; b++) {
			int c = n-a-b;
			if (max({abs(a-b), abs(b-c), abs(c-a)}) > 1)
				continue;
			for (int x=0; x<3; x++) {
				ad(z, dp[nuq%2][a][b][c][x]);
			}
		}
	}

	cout << z << '\n';
}