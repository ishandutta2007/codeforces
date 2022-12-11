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
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int nmax = 110;
const int tmax = 370;

int dp[tmax][nmax];
int nx[tmax][nmax];

void relax(int a, int cnt, int val) {
    if (nx[a][cnt] == -1) {
        nx[a][cnt] = val;
    }
    nx[a][cnt] = min(nx[a][cnt], val);
}

const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(all(t));

    int sum = 0;
    int lst = -1;
    for (int i = 0; i < n; ++i) {
        sum += t[i];
        if (sum > 710) {
            break;
        }
        lst = i;
    }

    if (lst == -1) {
        cout << "0 0\n";
        return 0;
    }

    vector<int> tmp;
    for (int i = 0; i <= lst; ++i) {
        tmp.pb(t[i]);
    }
    t = tmp;
    sum = 0;

    vector<int> fine(sz(t));
    fine.back() = 0;
    n = sz(t);
    for (int i = sz(t) - 2; i >= 0; --i) {
        fine[i] = t[i + 1] + fine[i + 1] + (n - i - 2) * t[i + 1];
    }

    //cout << fine[5] << " " << fine[4] << " " << fine[3] << "\n";

    int ans = inf;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 0; i < sz(t); ++i) {
        memset(nx, -1, sizeof(nx));
        if (i) {
            sum += t[i - 1];
        }
        for (int a = 0; a <= 350; ++a) {
            int b = sum - a;
            for (int cnt = 0; cnt <= i; ++cnt) {
                if (dp[a][cnt] == -1) {
                    continue;
                }
                assert(b >= 0);
                if (b + t[i] <= 360) {
                    relax(a, cnt + 1, dp[a][cnt] + b + t[i]);
                }
                if (a + t[i] <= 350) {
                    relax(a + t[i], cnt, dp[a][cnt]);
                } else {

                    int val = dp[a][cnt] + (a + t[i] - 350) + cnt * (a + t[i] - 350);
                    val += fine[i];
                    val += (sz(t) - i - 1) * (a + t[i] - 350 + b);
                    ans = min(ans, val);
                }
            }
        }

        memcpy(dp, nx, sizeof(dp));
    }

    if (ans == inf) {
        ans = 0;
    }

    cout << sz(t) << " " << ans << "\n";

}