#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>

typedef long long ll;
typedef long double ld;

using namespace std;

const int mod = 1000 * 1000 * 1000 + 7;

const int MX = 1000 * 1000 + 7;
vector<pair<int, int>> g[MX];
int timer;


void do_it(int a, int b, int ind, int len) {
    for (int j = 0; j < len; j++) {
        if (j == len - 1) {
            g[a].push_back({b, ind % 10});
        } else {
            g[a].push_back({timer, ind % 10});
            a = timer++;
        }
        ind /= 10;
    }
}

void get_edge(int ind) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    string s = to_string(ind);
    reverse(s.begin(), s.end());
    do_it(a, b, stoi(s), s.length());
    do_it(b, a, stoi(s), s.length());
}

const int INF = 1e9 + 7;
int used[MX];
vector<int> d(MX, INF);
int ans[MX];

void dfs(const vector<int>& a, int val = 0) {
    for (int i : a) ans[i] = val;

    for (int i = 0; i < 10; i++) {
        vector<int> to;
        for (int j : a) {
            for (const auto& k : g[j]) {
                if (k.second == i && !used[k.first] && d[k.first] == d[j] + 1) {
                    to.push_back(k.first);
                    used[k.first] = 1;
                }
            }
        }
        if (!to.empty())
            dfs(to, (val * 1ll * 10 + i) % mod);
    }
}

int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    timer = n;
    for (int i = 0; i < m; i++) {
        get_edge(i + 1);
    }

    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& to : g[v]) {
            if (d[to.first] == INF) {
                d[to.first] = d[v] + 1;
                q.push(to.first);
            }
        }
    }
    dfs({0});
    for (int i = 1; i < n; i++) {
        cout << ans[i] << '\n';
    }


    return 0;
}