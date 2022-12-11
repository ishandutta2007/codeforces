#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int nmax = 10;

int dp[nmax][nmax][nmax][nmax][nmax];
int nx[nmax][nmax][nmax][nmax][nmax];

void upd(int& x, int y) {
    if (x == -1) {
        x = y;
    } else {
        x = min(x, y);
    }
}

const int inf = 1e9;

mt19937 rr(2);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));
    dp[1][0][0][0][0] = 0;

    int n;
    //n = 2000;
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        int from, to;
        if (i < n) {
            //from = rr() % 9 + 1, to = i % 9 + 1;
            //assert(from >= 1 && from <= 9);
            cin >> from >> to;
        }
        memset(nx, -1, sizeof(nx));
        for (int j = 0; j < 4; ++j)
        for (int s = 1; s < nmax; ++s) {
            for (int a = nmax - 1; a >= 0; --a) {
                for (int b = nmax - 1; b >= 0; --b) {
                    for (int c = nmax - 1; c >= 0; --c) {
                        for (int d = nmax - 1; d >= 0; --d) {
                            if (dp[s][a][b][c][d] == -1) {
                                continue;
                            }
                            if (a != 0) {
                                upd(dp[a][0][b][c][d], dp[s][a][b][c][d] + abs(s - a));
                            }
                            if (b != 0) {
                                upd(dp[b][a][0][c][d], dp[s][a][b][c][d] + abs(s - b));
                            }
                            if (c != 0) {
                                upd(dp[c][a][b][0][d], dp[s][a][b][c][d] + abs(s - c));
                            }
                            if (d != 0) {
                                upd(dp[d][a][b][c][0], dp[s][a][b][c][d] + abs(s - d));
                            }
                        }
                    }
                }
            }
        }
        if (i < n) {
            for (int s = 1; s < nmax; ++s) {
                for (int a = nmax - 1; a >= 0; --a) {
                    for (int b = nmax - 1; b >= 0; --b) {
                        for (int c = nmax - 1; c >= 0; --c) {
                            for (int d = nmax - 1; d >= 0; --d) {
                                if (dp[s][a][b][c][d] == -1) {
                                    continue;
                                }
                                if (a == 0) {
                                    upd(nx[from][to][b][c][d], dp[s][a][b][c][d] + abs(s - from));
                                }
                                if (b == 0) {
                                    upd(nx[from][a][to][c][d], dp[s][a][b][c][d] + abs(s - from));
                                }
                                if (c == 0) {
                                    upd(nx[from][a][b][to][d], dp[s][a][b][c][d] + abs(s - from));
                                }
                                if (d == 0) {
                                    upd(nx[from][a][b][c][to], dp[s][a][b][c][d] + abs(s - from));
                                }
                            }
                        }
                    }
                }
            }
        }
        if (i == n) {
            int ans = -1;
            for (int s = 1; s < nmax; ++s) {
                //cout << s << " " << dp[s][0][0][0][0] << "\n";
                if (dp[s][0][0][0][0] == -1) {
                    continue;
                }
                upd(ans, dp[s][0][0][0][0]);
            }
            cout << ans + 2 * n << "\n";
        }
        memcpy(dp, nx, sizeof(dp));
    }

}