#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <cmath>
#include <memory.h>
#include <queue>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;

const ld PI = acosl(-1.);
const int N = 500555;

int w[N];
int len[N];
vector<int> g[N];
bool calced[N];
int d[N];
int used[N], iter;
int best, bestlen;

int fath(int x) {
    if (w[x] != x) w[x] = fath(w[x]);
    return w[x];
}

void un(int x, int y) {
    w[fath(x)] = fath(y);
}

void dfs(int x, int l = 0) {
    d[x] = l;
    used[x] = iter;
    if (l > bestlen) {
        bestlen = l;
        best = x;
    }

    for (int i = 0; i < g[x].size(); ++i) {
        if (used[ g[x][i] ] != iter) {
            dfs(g[x][i], l + 1);
        }
    }
}

void calc(int x) {
    x = fath(x);
    if (calced[x]) return;
    calced[x] = true;

    bestlen = -1; best = -1;
    ++iter;
    dfs(x);

    x = best;
    bestlen = -1; best = -1;
    ++iter;
    dfs(x);

    x = best;
    bestlen = -1; best = -1;
    ++iter;
    dfs(x);

    len[fath(best)] = bestlen;
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; ++i) w[i] = i;

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        un(a, b);
    }

    for (int i = 1; i <= n; ++i) {
        calc(i);
    }

    while (q--) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            int x;
            scanf("%d", &x);
            printf("%d\n", len[fath(x)]);
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            x = fath(x); y = fath(y);
            if (x == y) continue;

            int len1 = len[x], len2 = len[y];
            un(x, y);
            len[fath(x)] = max(((len1 + 1) / 2) + ((len2 + 1) / 2) + 1, max(len1, len2));
        }
    }

    return 0;
}