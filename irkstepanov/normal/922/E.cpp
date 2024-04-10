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
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 1e4 + 100;

ll dp[nmax];
ll nx[nmax];

void upd(int pos, ll val) {
    nx[pos] = max(nx[pos], val);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    ll w, b, x;
    cin >> n >> w >> b >> x;
    memset(dp, -1, sizeof(dp));

    dp[0] = w;

    vector<int> c(n), cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    for (int i = 0; i < n; ++i) {
        memset(nx, -1, sizeof(nx));
        for (int j = 0; j < nmax; ++j) {
            if (dp[j] == -1) {
                continue;
            }
            ll curr = min(dp[j] + x, w + b * j);
            for (int cnt = 0; cnt <= c[i]; ++cnt) {
                if (curr >= ll(cnt) * cost[i]) {
                    upd(j + cnt, curr - ll(cnt) * cost[i]);
                }
            }
        }
        memcpy(dp, nx, sizeof(nx));
    }

    int ans = 0;
    for (int i = 0; i < nmax; ++i) {
        if (dp[i] != -1) {
            ans = i;
        }
    }
    cout << ans << "\n";

}