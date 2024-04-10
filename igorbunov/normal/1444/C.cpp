#pragma GCC_OPTIMIZE("ofast")
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

#define data NE_data
#define rank NE_rank
#define endl '\n'

#define int long long
const int MAXN = 2000000;
const int INF = 1000000000;
const int MOD = 1000000007;

vector<int> g[MAXN];
int group[MAXN];
bool ban[MAXN];
bool used[MAXN];
vector<pair<int, int>> edges;
int c[MAXN];

int group_1[MAXN];
int now_g = 0;
void dfs(int v, int now = 0) {
    c[v] = now;
    used[v] = true;
    group_1[v] = now_g;
    for (auto u : g[v]) {
        if (used[u]) {
            if (c[u] == c[v]) {
                ban[group[v]] = true;
            }
        } else {
            dfs(u, 1 - now);
        }
    }
}

int kek[MAXN];

unordered_map<int, vector<pair<int, int>>> karta;


int pr[MAXN];
int rank[MAXN];

void make_set(int v) {
    pr[v] = v;
    rank[v] = 0;
}

int get_root(int v) {
    if (pr[v] == v) {
        return v;
    }
    return pr[v] = get_root(pr[v]);
}

void merge(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (a == b) {
        return;
    }
    pr[b] = a;
}

bool bad = false;

bool used1[MAXN];
int c1[MAXN];
vector<int> g1[MAXN];

void dfs1(int v, int now = 0) {
    c1[v] = now;
    used1[v] = true;
    for (auto u : g1[v]) {
        if (used1[u]) {
            if (c1[u] == c1[v]) {
                bad = true;
            }
        } else {
            dfs1(u, 1 - now);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> group[i];
        group[i]--;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (group[a] == group[b]) {
            g[a].push_back(b);
            g[b].push_back(a);
        } else {
            edges.push_back(make_pair(a, b));
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
            now_g++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += !ban[i];
    }
    for (auto p : edges) {
        int a = p.first;
        int b = p.second;
        if (!ban[group[a]] && !ban[group[b]]) {
            int gr1 = group[a];
            int gr2 = group[b];
            if (gr1 < gr2) {
                karta[gr1 * k + gr2].push_back(make_pair(a, b));
            } else {
                karta[gr2 * k + gr1].push_back(make_pair(b, a));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        kek[i] = -1;
    }
    int ans = cnt * (cnt - 1) / 2;
    for (auto p1 : karta) {
        bad = false;
        for (auto p : p1.second) {
            int a = p.first;
            int b = p.second;
            int c11 = c[a] == c[b];
            a = group_1[a];
            b = group_1[b];
            make_set(a);
            make_set(b);
            g1[a].clear();
            g1[b].clear();
            c1[a] = -1;
            c1[b] = -1;
            used1[a] = false;
            used1[b] = false;
            kek[a] = -1;
            kek[b] = -1;
        }
        for (auto p : p1.second) {
            int a = p.first;
            int b = p.second;
            int c11 = c[a] == c[b];
            a = group_1[a];
            b = group_1[b];
            if (c11) {
                merge(a, b);
            }
        }
        for (auto p : p1.second) {
            int a = p.first;
            int b = p.second;
            int c11 = c[a] == c[b];
            a = group_1[a];
            b = group_1[b];
            if (!c11) {
                a = get_root(a);
                b = get_root(b);
                g1[a].push_back(b);
                g1[b].push_back(a);
            }
        }
        for (auto p : p1.second) {
            int a = p.first;
            int b = p.second;
            int c1 = c[a] == c[b];
            a = group_1[a];
            b = group_1[b];
            if (!c1) {
                a = get_root(a);
                b = get_root(b);
                if (!used1[a]) {
                    dfs1(a);
                }
            }
        }
        ans -= bad;
    }
    cout << ans;
}