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

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void mul(int& a, int b) {
	ll c = ll(a) * b;
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

const int nmax = 2050;

int bin[nmax][nmax];

int main() {

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

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	int m;
	cin >> m;
	vector<int> x(m), y(m);
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		cin >> x[i];
		cnt += x[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> y[i];
	}

	vector<int> dp(cnt + 1);
	dp[0] = 1;
	for (int i = 0; i < m; ++i) {
		vector<int> nx(cnt + 1);
		for (int opn = 0; opn <= cnt; ++opn) {
			for (int cls = 0; cls <= opn + x[i] && cls <= y[i]; ++cls) {
				int z = opn + x[i];
				int val = dp[opn];
				mul(val, bin[z][cls]);
				if (z - cls <= cnt) {
					add(nx[z - cls], val);
				}
			}
		}
		/*for (int j = 0; j <= cnt; ++j) {
			cout << nx[j] << " ";
		}
		cout << "\n";*/
		dp.swap(nx);
	}

	/*for (int i = 1; i <= cnt; ++i) {
		mul(dp[0], i);
	}*/
	int sum = 0;
	for (int i = 0; i < m; ++i) {
		mul(dp[0], bin[cnt - sum][x[i]]);
		sum += x[i];
	}

	cout << dp[0] << "\n";

}