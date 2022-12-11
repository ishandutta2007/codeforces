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

const int ops = 200;

struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
};

ll dist2(const pt& a, const pt& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ld dist(const pt& a, const pt& b) {
    return sqrt(ld(dist2(a, b)));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    ld prob;
    cin >> prob;
    prob /= 1000.0;

    pt start;
    cin >> start.x >> start.y;
    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    ld lf = 0, rg = 100500;
    //ld lf = 4, rg = 4;
    for (int step = 0; step < ops; ++step) {
        ld r = (lf + rg) / 2;
        vector<ld> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 0; j < n; ++j) {
            vector<ld> nx(n + 1, 0);
            if (dist(p[j], start) <= r) {
                for (int t = 0; t < n; ++t) {
                    nx[t + 1] = dp[t];
                }
                dp.swap(nx);
            } else {
                if (r == 0) {
                    continue;
                }
                ld d = dist(p[j], start);
                ld x = exp(1 - d * d / r / r);
                for (int t = 0; t <= n; ++t) {
                    nx[t] += dp[t] * (1 - x);
                    if (t + 1 <= n) {
                        nx[t + 1] += dp[t] * x;
                    }
                }
                dp.swap(nx);
            }
        }
        ld sum = 0;
        for (int j = k; j <= n; ++j) {
            sum += dp[j];
        }
        if (sum >= 1 - prob) {
            rg = r;
        } else {
            lf = r;
        }
    }

    cout << fixed;
    cout.precision(20);
    cout << lf << endl;

}