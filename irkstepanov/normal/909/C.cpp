#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

const int nmax = 5050;

int dp[nmax][2];
int nx[nmax][2];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    dp[0][1] = 1;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        memset(nx, 0, sizeof(nx));
        if (s == "s") {
            int sum = 0;
            for (int j = nmax - 1; j >= 0; --j) {
                add(sum, dp[j][1]);
                nx[j][1] = sum;
            }
            for (int j = 0; j < nmax; ++j) {
                if (j + 1 < nmax) {
                    add(nx[j + 1][1], dp[j][0]);
                }
            }
        } else {
            int sum = 0;
            for (int j = nmax - 1; j >= 0; --j) {
                add(sum, dp[j][1]);
                nx[j][0] = sum;
            }
            for (int j = 0; j < nmax; ++j) {
                if (j + 1 < nmax) {
                    add(nx[j + 1][0], dp[j][0]);
                }
            }
        }
        /*if (i == 2) {
            for (int j = 0; j < nmax; ++j) {
                if (nx[j][0]) {
                    cout << "!" << j << " " << 0 << " " << nx[j][0] << "\n";
                }
                if (nx[j][1]) {
                    cout << "!" << j << " " << 1 << " " << nx[j][1] << "\n";
                }
            }
        }*/
        memcpy(dp, nx, sizeof(dp));
    }

    int ans = 0;
    for (int j = 0; j < nmax; ++j) {
        add(ans, dp[j][1]);
    }
    cout << ans << "\n";

}