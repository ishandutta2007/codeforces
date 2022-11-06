#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()


vector<int> pos[3];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	//srand(time(0));
	int n;
	cin >> n;
	string s;
	cin >> s;
	//random_shuffle(s.begin(), s.end());
	for(int i = 0; i < sz(s); i++) {
		if (s[i] == 'V') {
			pos[0].pb(i);
		}
		else if (s[i] == 'K') {
			pos[1].pb(i);
		}
		else {
			pos[2].pb(i);
		}
	}
	
	int cnt0 = sz(pos[0]);
	int cnt1 = sz(pos[1]);
	int cnt2 = sz(pos[2]);

	int *****dp = new int****[n+1];
	for(int i = 0; i <= n; i++) {
		dp[i] = new int***[3];
		for(int j = 0; j < 3; j++) {
			dp[i][j] = new int**[cnt0+1];
			for(int k = 0; k <= cnt0; k++) {
				dp[i][j][k] = new int*[cnt1+1];
				for(int l = 0; l <= cnt1; l++) {
					dp[i][j][k][l] = new int[cnt2+1];
					for(int m = 0; m <= cnt2; m++)
						dp[i][j][k][l][m] = 1e6;
				}
			}
		}
	}
	dp[0][2][0][0][0] = 0;

	
	for(int i = 0; i < n; i++) {
		for(int lst = 0; lst < 3; lst++) {
			for(int t0 = 0; t0 <= cnt0; t0++) {
				for(int t1 = 0; t1 <= cnt1; t1++) {
					for(int t2 = 0; t2 <= cnt2; t2++) {
						if (dp[i][lst][t0][t1][t2] > 1e5) continue;
						if (t0 != cnt0) { // take 0
							int cnt = 0;
							for(int x = cnt1 - 1; x >= t1; x--) {
								if (pos[0][t0] >= pos[1][x]) cnt++;
							}
							for(int x = cnt2 - 1; x >= t2; x--) {
								if (pos[0][t0] >= pos[2][x]) cnt++;
							}
							dp[i+1][0][t0+1][t1][t2] = min(dp[i+1][0][t0+1][t1][t2], dp[i][lst][t0][t1][t2] + cnt);
						}
						if (t1 != cnt1 && lst != 0) { // take 1
							int cnt = 0;
							for(int x = cnt0 - 1; x >= t0; x--) {
								if (pos[1][t1] >= pos[0][x]) cnt++;
							}
							for(int x = cnt2 - 1; x >= t2; x--) {
								if (pos[1][t1] >= pos[2][x]) cnt++;
							}
							dp[i+1][1][t0][t1+1][t2] = min(dp[i+1][1][t0][t1+1][t2], dp[i][lst][t0][t1][t2] + cnt);
						}
						if (t2 != cnt2) { // take 1
							int cnt = 0;
							for(int x = cnt0 - 1; x >= t0; x--) {
								if (pos[2][t2] >= pos[0][x]) cnt++;
							}
							for(int x = cnt1 - 1; x >= t1; x--) {
								if (pos[2][t2] >= pos[1][x]) cnt++;
							}
							dp[i+1][2][t0][t1][t2+1] = min(dp[i+1][2][t0][t1][t2+1], dp[i][lst][t0][t1][t2] + cnt);
						}
					}
				}
			}
		}
	}

	int res = dp[n][0][cnt0][cnt1][cnt2];
	res = min(res, dp[n][1][cnt0][cnt1][cnt2]);
	res = min(res, dp[n][2][cnt0][cnt1][cnt2]);
	printf("%d", res);

	return 0;
}