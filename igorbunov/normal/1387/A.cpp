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

#define int long long
#define endl '\n'

const int MAXN = 1000000;
const int INF = 1000000000;

int a[MAXN];
int b[MAXN];

bool used[MAXN];
vector<pair<int, int>> g[MAXN];
vector<int> now;

int kek = INF;

void dfs(int v) {
    used[v] = true;
    now.push_back(v);
    for (auto p : g[v]) {
        int u = p.first;
        int t = p.second;
        if (t == 1) {
            if (used[u]) {
                if (a[v] == -a[u]) {
                    if (b[v] + b[u] == 1) {
                        continue;
                    } else {
                        cout << "NO";
                        exit(0);
                    }
                } else {
                    if (kek == INF) {
                        if (a[v] == 1 && a[u] == 1) {
                            kek = 1 - b[v] - b[u];
                        } else {
                            kek = b[v] + b[u] - 1;
                        }
                    } else {
                        if (a[v] == 1 && a[u] == 1) {
                            if (kek != 1 - b[v] - b[u]) {
                                cout << "NO";
                                exit(0);
                            }
                        } else {
                            if (kek != b[v] + b[u] - 1) {
                                cout << "NO";
                                exit(0);
                            }
                        }
                    }
                }
            } else {
                a[u] = -a[v];
                b[u] = 1 - b[v];
                dfs(u);
            }
        } else {
            if (used[u]) {
                if (a[v] == -a[u]) {
                    if (b[v] + b[u] == 2) {
                        continue;
                    } else {
                        cout << "NO";
                        exit(0);
                    }
                } else {
                    if (kek == INF) {
                        if (a[v] == 1 && a[u] == 1) {
                            kek = 2 - b[v] - b[u];
                        } else {
                            kek = b[v] + b[u] - 2;
                        }
                    } else {
                        if (a[v] == 1 && a[u] == 1) {
                            if (kek != 2 - b[v] - b[u]) {
                                cout << "NO";
                                exit(0);
                            }
                        } else {
                            if (kek != b[v] + b[u] - 2) {
                                cout << "NO";
                                exit(0);
                            }
                        }
                    }
                }
            } else {
                a[u] = -a[v];
                b[u] = 2 - b[v];
                dfs(u);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    vector<double> ans(n);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            a[i] = 1;
            b[i] = 0;
            kek = INF;
            now.clear();
            dfs(i);
            if (kek == INF) {
                vector<int> lol;
                for (auto v : now) {
                    lol.push_back(-2 * b[v] / a[v]);
                }
                sort(lol.begin(), lol.end());
                kek = lol[lol.size() / 2];
            }
            for (auto v : now) {
                ans[v] = (double)(kek * a[v] + 2 * b[v]) / 2.0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(1) << ans[i] << " ";
    }
}