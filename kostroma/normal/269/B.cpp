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
void precalc();
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

//#define int li

int n, m;
int color[5050];
int dp[5050][5050];

const int INF = 1000000000;

int num[5050];

void solve(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> color[i];
		double x; cin >> x;
	}
	for (int i = 0; i < 5050; ++i)
		for (int j = 0; j < 5050; ++j)
			dp[i][j] = INF;

	for (int i = 0; i <= m + 1; ++i)
		dp[n][i] = 0;
	for (int i = 0; i <= n; ++i)
		dp[i][m + 1] = 0;

	for (int i = n - 1; i >= 0; --i) {
		++num[color[i]];
		for (int j = m; j >= 1; --j){ //  j  m
			if (color[i] <= j) {
				dp[i][j] = dp[i + 1][j];
				continue;
			}

			if (num[j] == 0) {
				dp[i][j] = dp[i][j + 1];
				continue;
			}

			dp[i][j] = min(dp[i][j], dp[i][j + 1] + num[j]);
			dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);

			//cout << i << ' '<< j << ' ' << dp[i][j] << "\n";
		}
	}

	cout << dp[0][1];

}