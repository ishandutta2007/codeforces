#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while (t--) {
		int n, k, r, c;
		cin >> n >> k >> r >> c;
		r--; c--;
		char out[n][n];
		rep(i, 0, n) rep(j, 0, n) out[i][j] = '.';

		out[r][c] = 'X';
		int xpos = c;
		int needed = n / k;
		while (needed--) {
			xpos += k;
			xpos %= n;
			out[r][xpos] = 'X';
		}

		rep(i, r+1, n) {
			rep(j, 0, n) {
				int prevj = (j-1);
				if (prevj < 0) prevj += n;

				if (out[i-1][prevj] == 'X') out[i][j] = 'X';
			}
		}

		for (int i = r-1; i >= 0; i--) {
			rep(j, 0, n) {
				int prevj = (j+1)%n;

				if (out[i+1][prevj] == 'X') out[i][j] = 'X';
			}
		}

		rep(i, 0, n) {
			rep(j, 0, n) cout << out[i][j];
			cout << endl;
		}
	}
}