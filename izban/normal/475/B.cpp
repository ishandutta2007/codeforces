#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 22;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m, cnt;
string a, b;
bool vis[maxn][maxn];
vector<pair<int, int> > e[maxn][maxn];

void dfs(int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = 1;
    cnt++;
    for (int k = 0; k < (int)e[i][j].size(); k++) {
        dfs(e[i][j][k].first, e[i][j][k].second);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) e[i][j].clear();
        cin >> a >> b;
        for (int i = 0; i < n; i++) {
            if (a[i] == '>') {
                for (int j = 0; j < m - 1; j++) {
                    e[i][j].push_back(make_pair(i, j + 1));
                }
            } else {
                for (int j = 1; j < m; j++) {
                    e[i][j].push_back(make_pair(i, j - 1));
                }
            }
        }
        for (int j = 0; j < m; j++) {
            if (b[j] == 'v') {
                for (int i = 0; i < n - 1; i++) {
                    e[i][j].push_back(make_pair(i + 1, j));
                }
            } else {
                for (int i = 1; i < n; i++) {
                    e[i][j].push_back(make_pair(i - 1, j));
                }
            }
        }
        
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt = 0;
                memset(vis, 0, sizeof(vis));
                dfs(i, j);
                ok &= cnt == n * m;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    
    return 0;
}