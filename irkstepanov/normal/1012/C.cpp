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

//typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef int ll;
//typedef pair<ll, ll> pll;
typedef double ld;

void upd(ll& x, ll y) {
    if (x == -1) {
        x = y;
    } else {
        x = min(x, y);
    }
}

const int nmax = 100500;

int a[nmax];
int dp[2][nmax][3];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int kmax = (n + 1) / 2;
    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = 0;
    dp[0][1][1] = 0;

    int ptr = 0;

    for (int i = 0; i + 1 < n; ++i) {
        memset(dp[ptr ^ 1], -1, sizeof(dp[ptr ^ 1]));
        for (int k = 0; k <= kmax; ++k) {
            if (dp[ptr][k][0] != -1) {
                upd(dp[ptr ^ 1][k][0], dp[ptr][k][0]);
                upd(dp[ptr ^ 1][k + 1][1], dp[ptr][k][0] + max(ll(0), a[i] - a[i + 1] + 1));
            }
            if (dp[ptr][k][1] != -1) {
                ll add = max(ll(0), a[i + 1] - a[i] + 1);
                if (a[i + 1] < a[i]) {
                    upd(dp[ptr ^ 1][k][0], dp[ptr][k][1] + add);
                } else {
                    upd(dp[ptr ^ 1][k][2], dp[ptr][k][1] + add);
                }
            }
            if (dp[ptr][k][2] != -1) {
                ll x = min(a[i], a[i - 1] - 1);
                upd(dp[ptr ^ 1][k][0], dp[ptr][k][2]);
                upd(dp[ptr ^ 1][k + 1][1], dp[ptr][k][2] + max(ll(0), x - a[i + 1] + 1));
            }
        }
        ptr ^= 1;
    }

    for (int k = 1; k <= kmax; ++k) {
        ll ans = -1;
        for (int i = 0; i < 3; ++i) {
            if (dp[ptr][k][i] != -1) {
                //cout << dp[ptr][k][i] << " ";
                //cout << ans << " " << dp[ptr][k][i] << "\n";
                upd(ans, dp[ptr][k][i]);
            }
        }
        cout << ans << " ";
    }
    cout << "\n";

}