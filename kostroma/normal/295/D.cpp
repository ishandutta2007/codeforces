#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
//void precalc();
#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	//cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	//cin >> t;
	//gen();
	while (t--)
		solve();
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

int c[6011][6011];

#define int li

int mod = 1000000007;

int n, m;

int dp[2013][2013]; //diff, height

int pref[2013][2013];

void solve () {
	cin >> n >> m;
	c[0][0] = 1;
	for (int i = 1; i < 6011; ++i) {
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}

	for (int d = 0; d < 2000; ++d) {
		dp[d][0] = 1;
		for (int k = 1; k < 2000; ++k) {
			dp[d][k] = ((d == 0) ? 0 : dp[d - 1][k]);
			dp[d][k] += c[2 * k + d - 1][d];
			dp[d][k] %= mod;
		}
	}

	/*for (int d = 0; d < 3; ++d)
		for (int k = 0; k < 3; ++k)
			cout << d <<' ' << k << ' ' <<dp[d][k] << "\n";*/

	for (int d = 0; d < 2000; ++d) {
		pref[d][0] = dp[d][0];
		for (int k = 1; k < 2000; ++k)
			pref[d][k] = (pref[d][k - 1] + dp[d][k]) % mod;
	}

	int ans = 0;

	for (int d = 0; d < 2000; ++d) {
		if (d + 2 > m)
			break;
		int res = 0;
		for (int verh = 0; verh < n; ++verh) {
			int niz = n - 1 - verh;
			res += pref[d][verh] * (pref[d][niz] - ((niz == 0) ? 0 : pref[d][niz - 1]));
			res %= mod;
		}

		//cout << d << ' ' << res << "\n";

		res *= (m - d - 1);
		ans += res;
		ans %= mod;
	}

	cout << ans;

}