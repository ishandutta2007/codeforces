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

const int MAXN = 2000000;

vector<vector<int>> g(MAXN), e(MAXN);
vector<vector<int>> G(MAXN);
vector<char> used(MAXN);
vector<int> order;
vector<int> order1;
vector<int> component(MAXN);
int ans_count = -1;

void top_sort_1(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        if (!used[g[v][i]]) {
            top_sort_1(g[v][i]);
        }
    }
    order.push_back(v);
}

vector<vector<int>> kek(MAXN);

void dfs(int v) {
    used[v] = true;
    component[v] = ans_count;
    kek[ans_count].push_back(v);
    for (int i = 0; i < e[v].size(); i++) {
        if (!used[e[v][i]]) {
            dfs(e[v][i]);
        }
    }
}

vector<int> inds(MAXN);

signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        e[b].push_back(a);
        edges.push_back(make_pair(a, b));
    }
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < n ; i++) {
        if (!used[i]) {
            top_sort_1(i);
        }
    }
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int v = order[n - i - 1];
        if (!used[v]) {
            ans_count++;
            dfs(v);
        }
    }
    ans_count++;
    vector<int> kek_cnt(n);
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i].first;
        int b = edges[i].second;
        if (component[a] != component[b]) {
            G[component[a]].push_back(component[b]);
            kek_cnt[component[b]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    queue<int> q;
    for (int i = 0; i < ans_count; i++) {
        if (kek_cnt[i] == 0) {
            q.push(i);
        }
    }

    int ans = -1;

    while (q.size()) {
        int now = q.front();
        if (ans == -1) {
            ans = now;
            q.pop();
            continue;
        }
        int v = kek[ans][inds[ans]];
        int u = kek[now][inds[now]];
        cout << "? " << v + 1 << " " << u + 1 << endl;
        int res;
        cin >> res;
        if (res == 1) {
            inds[now]++;
            if (inds[now] == kek[now].size()) {
                q.pop();
                for (auto ui : G[now]) {
                    kek_cnt[ui]--;
                    if (kek_cnt[ui] == 0) {
                        q.push(ui);
                    }
                }
            }
        } else {
            inds[ans]++;
            q.pop();
            if (inds[ans] == kek[ans].size()) {
                for (auto ui : G[ans]) {
                    kek_cnt[ui]--;
                    if (kek_cnt[ui] == 0) {
                        q.push(ui);
                    }
                }
            } else {
                q.push(ans);
            }
            ans = now;
        }
    }
    cout << "! " << kek[ans][inds[ans]] + 1 << endl;
    return 0;
}