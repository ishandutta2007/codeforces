#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <assert.h>
#include <fstream>
#include <cstdlib>
#include <random>
#include <iomanip>

using namespace std;

#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()

const long long MOD = (long long)2432902008176640000;
const long long MAX_N = (long long) 100;

const int mod = 998244353;

long long binPow(long long a, long long b) {
    if (b == 0)
        return 1;

    long long ans = binPow(a, b / 2);
    ans = ans * ans % mod;

    if (b % 2)
        ans = ans * a % mod;

    return ans;
}

const int inf = 1e9;
const int maxn = 3e5 + 100;

vector<int> dx{1, -1, 0 , 0};
vector<int> dy{0,  0, 1, -1};
int x[maxn], y[maxn];

int used[maxn];
int deleted[maxn];
int timer5;
int sizeOfTree[maxn];

int t[maxn][4];
int g[maxn][4];

void getTreeSizes(int v, int p = -1) {
    used[v] = timer5;
    sizeOfTree[v] = 1;    
    for (int i = 0; i < 4; i++) {
        int nx = x[v] + dx[i], ny = y[v] + dy[i];
        int to = g[v][i];

        if (to == -1) {
            continue;
        }

        if (used[to] != timer5 && !deleted[to]) {
            getTreeSizes(to, v);
            sizeOfTree[v] += sizeOfTree[to];
            t[v][i] = 1;
        } else {
            t[v][i] = 0;
            if (to == p) {
                t[v][i] = 1;
            }
        }
    }
}

int cntLayers;

vector<int> fnwh[maxn][2], fnwv[maxn][2];
vector<int> hor[maxn], ver[maxn];

pair<int, int> dsthor[maxn][21], dstver[maxn][21];
int layers[maxn][21];

int dist[maxn];
int us3[maxn];
int which[maxn];
int timer2;

void bfs(const vector<int>& st, int curLayer) {
    queue<int> q;
    timer2++;

    for (int i = 0; i < st.size(); i++) {
        int v = st[i];
        dist[v] = 0;
        which[v] = i;
        us3[v] = timer2;
        q.push(v);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (curLayer != -1) {
            int curSz = ++layers[v][0];
            assert(curSz < 21);
            layers[v][curSz] = curLayer;
            dsthor[v][curSz-1] = {dist[v], which[v]};
        } else {
            int curSz = layers[v][0];
            dstver[v][curSz-1] = {dist[v], which[v]};
        }
        
        for (int i = 0; i < 4; i++) {
            int to = g[v][i];
            if (to == -1) {
                continue;
            }
            int dto = us3[to] == timer2 ? dist[to] : inf;
            if (!deleted[to] && dto > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                which[to] = which[v];
                us3[to] = timer2;
                q.push(to);
            }
        }
    }
}

#define mp make_pair

void buildingDfs(int start) {
    ++timer5;
    getTreeSizes(start);

    int centroid = -1;
    int N = sizeOfTree[start];
 
    int p = -1, v = start;
    while (centroid == -1) {
        pair<int, int> maxSon = mp(0, -1);
        for (int i = 0; i < 4; i++) {
            int to = g[v][i];

            if (to == -1) {
                continue;
            }
            if (t[v][i] && !deleted[to] && to != p) {
                maxSon = max(maxSon, mp(sizeOfTree[to], to));
            }
        }
        if (maxSon.first > N / 2) {
            p = v;
            v = maxSon.second;
        } else centroid = v;
    }

    int curLayer = cntLayers++;
    
    v = centroid;
    while (g[v][3] != -1 && !deleted[g[v][3]]) {
        v = g[v][3];
    }
    while (v != -1 && !deleted[v]) {
        hor[curLayer].push_back(v);
        v = g[v][2];
    }

    v = centroid;
    while (g[v][1] != -1 && !deleted[g[v][1]]) {
        v = g[v][1];
    }
    while (v != -1 && !deleted[v]) {
        ver[curLayer].push_back(v);
        v = g[v][0];
    }

    // add to layers in bfs

    bfs(hor[curLayer], curLayer);
    bfs(ver[curLayer], -1);

    fnwh[curLayer][0].assign(hor[curLayer].size() + 1, inf);
    fnwh[curLayer][1].assign(hor[curLayer].size() + 1, inf);
    fnwv[curLayer][0].assign(ver[curLayer].size() + 1, inf);
    fnwv[curLayer][1].assign(ver[curLayer].size() + 1, inf);

    for (auto v : hor[curLayer]) {
        deleted[v] = 1;
    }
    for (auto v : ver[curLayer]) {
        deleted[v] = 1;
    }

    for (auto v : hor[curLayer]) {
        int i = x[v], j = y[v];
        for (int k = 0; k < 2; k++) {
            int to = g[v][k];
            if (to != -1 && !deleted[to]) {
                buildingDfs(to);
            }
        }
    }

    for (auto v : ver[curLayer]) {
        int i = x[v], j = y[v];
        for (int k = 2; k < 4; k++) {
            int to = g[v][k];
            if (to != -1 && !deleted[to]) {
                buildingDfs(to);
            }
        }
    }
}

void fnwupd(vector<int>& tree, int pos, int val) {
    pos++;
    while (pos < tree.size()) {
        tree[pos] = min(tree[pos], val);
        pos += pos & -pos;
    }
}

int fnwget(vector<int>& tree, int pos) {
    pos++;
    int res = inf;
    while (pos > 0) {
        res = min(res, tree[pos]);
        pos -= pos & -pos;
    }
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    // dstver.resize(n);
    // dsthor.resize(n);

    map<pair<int, int>, int> ids;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        ids[{x[i], y[i]}] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            g[i][j] = -1;
            int nx = x[i] + dx[j], ny = y[i] + dy[j];
            if (ids.count({nx, ny})) {
                g[i][j] = ids[make_pair(nx, ny)];
            }
        }
    }

    buildingDfs(0);
    int q;
    cin >> q;

    // for (int i = 0; i < n; i++) {
    //     cout << layers[i][0] << endl;
    // }
    // return 0;

    auto mark = [&](int v) {
        for (int j = 0; j < layers[v][0]; j++) {
            int id = layers[v][j+1];
            {
                // upd hor
                auto [d, pos] = dsthor[v][j];
                fnwupd(fnwh[id][0], hor[id].size() - pos - 1, d + pos);
                fnwupd(fnwh[id][1], pos, d - pos);
            }
            {
                // upd ver
                auto [d, pos] = dstver[v][j];
                fnwupd(fnwv[id][0], ver[id].size() - pos - 1, d + pos);
                fnwupd(fnwv[id][1], pos, d - pos);
            }
        }
    };

    auto get = [&](int v) {
        int res = inf;
        for (int j = 0; j < layers[v][0]; j++) {
            int id = layers[v][j+1];
            {
                // get hor
                auto [d, pos] = dsthor[v][j];

                int re1 = fnwget(fnwh[id][0], hor[id].size() - pos - 1) + d - pos;
                int re2 = fnwget(fnwh[id][1], pos) + d + pos;

                if (re1 < res) {
                    res = re1;
                }
                if (re2 < res) {
                    res = re2;
                }
            }
            {
                // get ver
                auto [d, pos] = dstver[v][j];

                int re1 = fnwget(fnwv[id][0], ver[id].size() - pos - 1) + d - pos;
                int re2 = fnwget(fnwv[id][1], pos) + d + pos;

                if (re1 < res) {
                    res = re1;
                }
                if (re2 < res) {
                    res = re2;
                }
            }
        }
        if (res > (int)1e6) {
            res = -1;
        }
        return res;
    }; 


    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        int v = ids[{x, y}];

        if (t == 1) {
            mark(v);
        } else {
            printf("%d\n", get(v));
        }
    }
    return 0;
}