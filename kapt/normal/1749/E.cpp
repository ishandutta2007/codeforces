#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 100;
int w[MAXN];
vector<int> g[MAXN];

int n, m;

int get(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return -1;
    return i * m + j;
}

string arr[MAXN];

int d[MAXN], p[MAXN];

pair<vector<int>, int> bfs(int s, int t) {
    fill(d, d + n * m + 2, MAXN);
    d[s] = 0;
    deque<int> q;
    q.push_back(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto u : g[v]) {
            if (w[u] == 2) continue;
            if (d[u] > d[v] + w[u]) {
                d[u] = d[v] + w[u];
                p[u] = v;
                if (w[u]) {
                    q.push_back(u);
                } else {
                    q.push_front(u);
                }
            }
        }
    }
    vector<int> ans;
    if (d[t] == MAXN) return {ans, MAXN};
    int res = d[t];
    while(p[t] != s) {
        ans.push_back(p[t]);
        t = p[t];
    }
    return {ans, res};
}

int main() {
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n >> m;
        for (int i = 0; i < n * m + 2; ++i) {
            w[i] = 1;
        }
        int s = n * m, t = n * m + 1;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == '#') {
                    w[get(i, j)] = 0;
                    for (int a = 0; a < 2; ++a) {
                        for (int b = 0; b < 2; ++b) {
                            if (get(i + a + b - 1, j + a - b) != -1) {
                                /// cout << i + a + b - 1 << " " << j + a - b << endl;
                                w[get(i + a + b - 1, j + a - b)] = 2;
                            }
                        }
                    }
                }
            }
        }
        vector<int> ans;
        int cnt = n * m;
        for (int rem = 0; rem < 2; ++rem) {
            for (int i = 0; i < n * m + 2; ++i) {
                g[i].clear();
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if ((i + j) % 2 != rem) continue;
                    if (j == 0) {
                        g[s].push_back(get(i, j));
                    }
                    if (j == m - 1) {
                        g[get(i, j)].push_back(t);
                    }
                    for (int a = -1; a < 2; a += 2) {
                        for (int b = -1; b < 2; b += 2) {
                            if (get(i + a, j + b) != -1) {
                                g[get(i, j)].push_back(get(i + a, j + b));
                            }
                        }
                    }
                }
            }
            auto res = bfs(s, t);
            if (res.second < cnt) {
                cnt = res.second;
                ans = res.first;
            }
        }
        if (cnt == n * m) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (auto elem : ans) {
                arr[elem / m][elem % m] = '#';
            }
            for (int i = 0; i < n; ++i) {
                cout << arr[i] << endl;
            }
        }
    }
    return 0;
}