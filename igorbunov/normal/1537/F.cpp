#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
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

vector<int> g[200000];
vector<int> val(200000);
vector<bool> used(200000);
vector<int> c(200000);

bool was = false;
void dfs_check(int v, int now = 0, int p = -1) {
    c[v] = now;
    used[v] = true;
    for (auto u: g[v]) {
        if (u == p) {
            continue;
        }
        if (used[u] && c[u] == c[v]) {
            was = true;
            break;
        }
        if (used[u]) {
            continue;
        }
        dfs_check(u, 1 - now, v);
    }
}

void dfs(int v, int p = -1) {
    used[v] = true;
    for (auto u: g[v]) {
        if (used[u]) {
            continue;
        }
        dfs(u, v);
    }
    if (p != -1) {
        val[p] -= val[v];
        val[v] = 0;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    was = false;
    vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++) {
        g[i].clear();
        c[i] = 0;
        used[i] = false;
        cin >> arr1[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
        val[i] = arr1[i] - arr2[i];
        sum += val[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs_check(0);
    if (sum % 2) {
        cout << "NO\n";
        return;
    }
    if (was) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }
    dfs(0);
    if (val[0] != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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