#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
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
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 
 
#define int long long
#define endl "\n"

const int MAXN = 200000;
vector<int> g[MAXN];
vector<int> dp_up(MAXN);
vector<pair<int, int>> dp_down1(MAXN);
vector<pair<int, int>> dp_down2(MAXN);
vector<pair<int, int>> dp_down3(MAXN);

int n, k;

void dfs_d(int v, int p = -1) {
    int v1 = 0;
    int i1 = -1;
    int v2 = -1;
    int i2 = -1;
    int v3 = -1;
    int i3 = -1;

    for (auto u: g[v]) {
        if (u != p) {
            dfs_d(u, v);

            if (v1 < dp_down1[u].first + 1) {
                v3 = v2;
                i3 = i2;
                v2 = v1;
                i2 = i1;
                v1 = dp_down1[u].first + 1;
                i1 = u;
            } else {
                if (v2 < dp_down1[u].first + 1) {
                    v3 = v2;
                    i3 = i2;
                    v2 = dp_down1[u].first + 1;
                    i2 = u;
                } else {
                    if (v3 < dp_down1[u].first + 1) {
                        v3 = dp_down1[u].first + 1;
                        i3 = u;
                    }
                }
            }
        }
    }
    dp_down1[v] = make_pair(v1, i1);
    dp_down2[v] = make_pair(v2, i2);
    dp_down3[v] = make_pair(v3, i3);
}

void dfs_u(int v, int p = -1) {
    for (auto u: g[v]) {
        if (p != u) {
            dp_up[u] = dp_up[v] + 1;
            if (u != dp_down1[v].second && dp_down1[v].second != -1) {
                dp_up[u] = max(dp_up[u], 1 + dp_down1[v].first);
            } else {
                if (u != dp_down2[v].second && dp_down2[v].second != -1) {
                    dp_up[u] = max(dp_up[u], 1 + dp_down2[v].first);
                }
            }
            dfs_u(u, v);
        }
    }
}

int ansd = -1;
int ansi = -1;
void dfs57(int v, int p = -1, int dist = 0) {
    if (dist > ansd) {
        ansd = dist;
        ansi = v;
    }

    for (auto u: g[v]) {
        if (u != p) {
            dfs57(u, v, dist + 1);
        }
    }
}

vector<int> diam;
vector<int> now;
int t1, t2;

void dfs58(int v, int p = -1) {
    now.push_back(v);
    if (v == t2) {
        diam = now;
    }
    for (auto u: g[v]) {
        if (u != p) {
            dfs58(u, v);
        }
    }
    now.pop_back();
}

vector<bool> used_d(MAXN);
vector<int> ans(MAXN);

void dfs59(int v, int p = -1) {
    for (auto u: g[v]) {
        if (u != p && !used_d[u]) {
            ans[u] = (ans[v] + 1) % k;
            dfs59(u, v);
        }
    }
}

void dfs60(int v, int p = -1) {
    for (auto u: g[v]) {
        if (u != p && !used_d[u]) {
            ans[u] = (ans[v] - 1 + k) % k;
            dfs60(u, v);
        }
    }
}
 
signed main() {
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dp_up[0] = 0;
    dfs_d(0);
    dfs_u(0);

    for (int i = 0; i < n; i++) {
        vector<int> arr;
        if (i != 0) {
            arr.push_back(dp_up[i]);
        }

        if (dp_down1[i].second != -1) {
            arr.push_back(dp_down1[i].first);
        }
        if (dp_down2[i].second != -1) {
            arr.push_back(dp_down2[i].first);
        }
        if (dp_down3[i].second != -1) {
            arr.push_back(dp_down3[i].first);
        }

        if (arr.size() > 2) {
            sort(arr.rbegin(), arr.rend());

            if (k != 2 && arr[1] + arr[2] >= k - 1 && arr[2] != 0) {
                cout << "No \n";
                return 0;
            }
        }
    }

    dfs57(0);
    t1 = ansi;
    ansd = -1;
    ansi = -1;
    dfs57(t1);
    t2 = ansi;
    dfs58(t1);
    for (int i = 0; i < diam.size(); i++) {
        used_d[diam[i]] = true;
    }
    int now_ans = 0;

    for (int i = 0; i < diam.size(); i++) {
        ans[diam[i]] = now_ans;
        now_ans++;
        if (now_ans == k) {
            now_ans = 0;
        }
    }

    for (int i = 0; i < diam.size() / 2; i++) {
        dfs60(diam[i]);
    }

    for (int i = diam.size() / 2; i < diam.size(); i++) {
        dfs59(diam[i]);
    }
    cout << "Yes \n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }

}