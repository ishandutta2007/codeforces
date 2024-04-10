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

vector<int> g[MAXN];
vector<int> l(MAXN), r(MAXN), dp0(MAXN), dp1(MAXN); 

void dfs(int v, int p = -1) {
    for (auto u: g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }
    dp0[v] = 0;
    dp1[v] = 0;
    //took l
    if (p != -1) {
        dp0[v] += abs(l[v] - l[p]);
    }
    for (auto u: g[v]) {
        if (u == p) {
            continue;
        }
        dp0[v] += dp0[u];
    }
    if (p != -1) {
        dp1[v] += abs(l[v] - r[p]);
    }
    for (auto u: g[v]) {
        if (u == p) {
            continue;
        }
        dp1[v] += dp0[u];
    }
    //took r
    int now0 = 0;
    int now1 = 0;
    if (p != -1) {
        now0 += abs(r[v] - l[p]);
    }
    for (auto u: g[v]) {
        if (u == p) {
            continue;
        }
        now0 += dp1[u];
    }
    if (p != -1) {
        now1 += abs(r[v] - r[p]);
    }
    for (auto u: g[v]) {
        if (u == p) {
            continue;
        }
        now1 += dp1[u];
    }
    dp0[v] = max(dp0[v], now0);
    dp1[v] = max(dp1[v], now1);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        g[i].clear();
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
    cout << max(dp0[0], dp1[0]) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}