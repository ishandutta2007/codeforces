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

const int maxn = 2222;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n;
int a[maxn][maxn];
bool ok;
vector<pair<int, pair<int, int> > > v;
vector<int> e[maxn];
int p[maxn], cnt[maxn];

void dfs(int v, int start, ll cur, int p) {
    ok &= cur == a[start][v];
    for (int i = 0; i < (int)e[v].size(); i++) {
        int to = e[v][i];
        if (to == p) continue;
        dfs(to, start, cur + a[v][to], v);
    }
}

int get(int x) {
    if (p[x] == x) return x;
    return p[x] = get(p[x]);
}
    
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (scanf("%d", &n) == 1) {
    //{
        //n = 2000;
        ok = 1;
        v.clear();
        v.reserve(n * n);
        for (int i = 1; i <= n; i++) {
            e[i].clear();
            p[i] = i;
            cnt[i] = 1;
            for (int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
                //a[i][j] = rand() % (int)1e9;
                if (i == j) ok &= a[i][j] == 0;
                else if (i < j) {
                    v.push_back(make_pair(a[i][j], make_pair(i, j)));
                    ok &= a[i][j] != 0;
                }
                if (j < i) {
                    ok &= a[i][j] == a[j][i];
                }
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < (int)v.size(); i++) {
            int U = v[i].second.first, V = v[i].second.second;
            int cU = get(U);
            int cV = get(V);
            if (cU == cV) continue;
            if (cnt[cU] < cnt[cV]) swap(cU, cV);
            e[U].push_back(V);
            e[V].push_back(U);
            p[cV] = cU;
            cnt[cU] += cnt[cV];
        }
        for (int i = 1; i <= n; i++) {
            dfs(i, i, 0, -1);
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    
    return 0;
}