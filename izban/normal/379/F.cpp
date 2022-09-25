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
 

using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int h[maxn];
int p[maxn][19];
int v1, v2, dist;

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int dif = h[u] - h[v];
    for (int i = 0; i < 19; i++) if ((1 << i) & (dif)) u = p[u][i];
    
    for (int i = 18; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    if (u != v) {
        assert(p[u][0] == p[v][0]);
        u = p[u][0];
    }
    return u;
}

void tryupd(int u, int v) {
    int w = lca(u, v);
    //cerr << u << " " << h[u] << " " << v << " " << h[v] << " " << w << " " << h[w] << endl;
    if (h[u] + h[v] - 2 * h[w] > dist) {
        v1 = u;
        v2 = v;
        dist = h[u] + h[v] - 2 * h[w];
    }
}

void add(int u, int v) {
    h[v] = h[u] + 1;
    p[v][0] = u;
    for (int i = 1; i < 19; i++) {
        p[v][i] = p[p[v][i - 1]][i - 1];
    }
    
    int V1 = v1, V2 = v2;
    tryupd(v, V1);
    tryupd(v, V2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    n = 4;
    for (int i = 0; i < 19; i++) p[1][i] = 1;
    h[1] = 0;
    h[2] = h[3] = h[4] = 1;
    for (int i = 0; i < 19; i++) for (int j = 2; j <= 4; j++) p[j][i] = 1;
    v1 = 2;
    v2 = 3;
    dist = 2;
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int v;
        cin >> v;
        add(v, ++n);
        add(v, ++n);
        cout << dist << endl;
    }

	return 0;
}