#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cstdlib>
#include <utility>
#include <limits>
#include <cstring>

using namespace std;

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<double, double> pdd;
const ll INF = std::numeric_limits<ll>::max() / 2;

const int MAXN = 2 * 1000 * 100 + 5;

ll dp[MAXN][2];

std::vector<int> values;
std::vector<std::vector<int>> al;

ll finalSolve(int v);

ll solve(int v, int remain) {
    ll& res = dp[v][remain];
    if (res != -INF) {
        return res;
    }
    res = 0;

    if (remain == 1) {
        // take root
        std::vector<ll> best(2, -INF);
        best[1] = values[v];
        for (const auto to: al[v]) {
            std::vector<ll> newBest(2, -INF);
            for (int x = 0; x < 2; ++x) {
                ll val = solve(to, x);
                for (int cur = 0; cur < 2; ++cur) {
                    newBest[cur ^ x] = std::max(
                            newBest[cur ^ x], best[cur] + val);
                }
            }
            best = newBest;
        }
        res = max(res, best[remain]);
    }

    std::vector<ll> best(2, -INF);
    best[0] = 0;
    for (const auto to: al[v]) {
        std::vector<ll> newBest(2, -INF);
        for (int x = 0; x < 2; ++x) {
            ll val = solve(to, x);
            for (int cur = 0; cur < 2; ++cur) {
                newBest[cur ^ x] = std::max(
                        newBest[cur ^ x], best[cur] + val);
            }
        }
        best = newBest;
    }
    res = max(res, best[remain]);
    //std::cerr << v << " " << remain << " " << res << std::endl;

    return res;
}

ll finalSolve(int v) {
    return std::max(solve(v, 0), solve(v, 1));
}

int main() {
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j] = -INF;
        }
    }
    int n;
    cin >> n;
    al.resize(n);
    for (int i = 0; i < n; ++i) {
        int parent, cost;
        cin >> parent >> cost;
        if (parent != -1) {
            al[parent - 1].emplace_back(i);
        }
        values.push_back(cost);
    }
    ll res = finalSolve(0);
    cout << res << endl;
    return 0;
}