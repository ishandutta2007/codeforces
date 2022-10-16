#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1000000007;
const int INF = 2000000000;
const int MAXN = 100000;

int bin_pow(int a, int b) {
    if (!b) {
        return 1;
    }
    if (b % 2 == 0) {
        int c = bin_pow(a, b / 2);
        return (c * c) % MOD;
    } else {
        return (bin_pow(a, b - 1) * a) % MOD;
    }
}

vector<int> g[200];

int timer = 0;
int tin[200];
int tout[200];

void dfs(int v, int p = -1) {
    tin[v] = timer++;
    for (auto u: g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }
    tout[v] = timer++;
}

bool is_ancestor(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

vector<int> now;
vector<int> now1;

void dfs1(int v, int need, int p = -1) {
    now.push_back(v);
    if (now1.size()) {
        return;
    }
    if (v == need) {
        now1 = now;
        return;
    }
    for (auto u: g[v]) {
        if (u == p) {
            continue;
        }
        dfs1(u, need, v);
    }
    now.pop_back();
}

bool used2[200];

int cnt = 0;
void dfs2(int v, int p = -1) {
    cnt++;
    for (auto u: g[v]) {
        if (u == p || used2[u]) {
            continue;
        }
        dfs2(u, v);
    }
}


int p[400][400];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= 300; i++) {
        p[i][0] = 1;
    }
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            p[i][j] = (p[i - 1][j] + p[i][j - 1]) * bin_pow(2, MOD - 2);
            p[i][j] %= MOD;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    int ans = 0;

    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            int was = ans;
            for (int i = 0; i < n; i++) {
                if (i == a) {
                    continue;
                }
                if (i == b) {
                    ans += 2;
                    continue;
                }

                now.clear();
                now1.clear();

                if (is_ancestor(b, a)) {
                    dfs1(b, a);
                    if (is_ancestor(a, i)) {
                        continue;
                    }
                    if (is_ancestor(now1[1], i)) {
                        //ans++;
                        continue;
                    }
                    ans += 2;
                    continue;
                }
                if (is_ancestor(a, b)) {
                    dfs1(a, b);
                    if (is_ancestor(b, i)) {
                        ans += 2;
                        continue;
                    }
                    if (is_ancestor(now1[1], i)) {
                        //ans++;
                        continue;
                    }
                    continue;
                }

                if (is_ancestor(b, i)) {
                    ans += 2;
                    continue;
                }
                if (is_ancestor(a, i)) {
                    continue;
                }
            }
        }
    }

    ans *= bin_pow(2, MOD - 2);
    ans %= MOD;
    ans *= bin_pow(n, MOD - 2);
    ans %= MOD;
    int kek = bin_pow(n, MOD - 2);
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            now.clear();
            now1.clear();
            dfs1(a, b);
            for (int i = 0; i < n; i++) {
                used2[i] = false;
            }
            used2[a] = true;
            used2[b] = true;
            for (int i = 1; i < (int)now1.size() - 1; i++) {
                used2[now1[i]] = true;
            }

            for (int i = 1; i < (int)now1.size() - 1; i++) {
                cnt = 0;
                dfs2(now1[i]);
                int now3 = cnt * p[i][(int)now1.size() - 1 - i];
                now3 %= MOD;
                now3 *= kek;
                now3 %= MOD;
                ans += now3;
                ans %= MOD;
                //used2[now1[i]] = true;
            }
        }
    }
    cout << ans;

}