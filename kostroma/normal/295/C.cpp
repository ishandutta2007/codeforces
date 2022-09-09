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

#define int li

int mod = 1000000007;
int n, k;
int num50 = 0, num100 = 0;

int c[100][100];

int dp[51][51][2];
int ways[51][51][2];

struct state {
	int n50, n100, who;
	state() {}
	state(int n50, int n100, int who):n50(n50), n100(n100), who(who) {}
};

int getDp(state cur) { 
	return dp[cur.n50][cur.n100][cur.who];
}

int getWays(state cur) {
	return ways[cur.n50][cur.n100][cur.who];
}

void fillDp (state cur, int val) {
	dp[cur.n50][cur.n100][cur.who] = val;
}

void fillWays (state cur, int val) {
	ways[cur.n50][cur.n100][cur.who] = val;
}

void addWays (state cur, int val) {
	ways[cur.n50][cur.n100][cur.who] += val;
	ways[cur.n50][cur.n100][cur.who] %= mod;
}


void solve () {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int cur; cin >> cur;
		if (cur == 50)
			num50++;
		else
			num100++;
	}

	c[0][0] = 1;
	for (int i = 1; i < 100; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}

	memset(dp, -1, sizeof dp);

	dp[num50][num100][0] = 0;
	ways[num50][num100][0] = 1;

	state start = state(num50, num100, 0);

	queue <state> q;
	q.push(start);

	while (!q.empty()) {
		state cur = q.front();
		q.pop();

		int dist = getDp(cur);
		int curWays = getWays(cur);
		state nex;

		if (cur.who == 0) {
			for (int i = 0; i <= cur.n50; ++i)
				for (int j = 0; j <= cur.n100; ++j)
					if (i + j > 0 && i * 50 + j * 100 <= k) {
						nex = state(cur.n50 - i, cur.n100 - j, 1);
						if (getDp(nex) == -1) {
							fillDp(nex, dist + 1);
							fillWays(nex, ((curWays * c[cur.n50][i]) % mod * c[cur.n100][j]) % mod);
							q.push(nex);
						}
						else
							if (getDp(nex) == dist + 1) {
								addWays(nex, ((curWays * c[cur.n50][i]) % mod * c[cur.n100][j]) % mod);
							}
					}
		}
		else {
			for (int i = 0; i <= num50 - cur.n50; ++i)
				for (int j = 0; j <= num100 - cur.n100; ++j)
					if (i + j > 0 && i * 50 + j * 100 <= k) {
						nex = state(cur.n50 + i, cur.n100 + j, 0);
						if (getDp(nex) == -1) {
							fillDp(nex, dist + 1);
							fillWays(nex, ((curWays * c[num50 - cur.n50][i]) % mod * c[num100 - cur.n100][j]) % mod);
							q.push(nex);
						}
						else
							if (getDp(nex) == dist + 1) {
								addWays(nex, ((curWays * c[num50 - cur.n50][i]) % mod * c[num100 - cur.n100][j]) % mod);
							}
					}
		}
	}

	cout << dp[0][0][1] << "\n" <<ways[0][0][1];


}