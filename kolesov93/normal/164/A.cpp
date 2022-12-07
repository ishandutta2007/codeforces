#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;

#define N 222222

int ke;
int fir[N], nxt[N], tov[N];
int f[N];
bool d1[N], d2[N];
int n,m;

void add(int x, int y) {
    nxt[++ke] = fir[x]; fir[x] = ke; tov[ke] = y;
    nxt[++ke] = fir[y]; fir[y] = ke; tov[ke] = x;
}

void dfs(int x) {
    d1[x] = true;
    for (int t = fir[x]; t; t = nxt[t])
        if (t & 1)
            if (f[ tov[t] ] != 1 && !d1[ tov[t] ]) {
                dfs(tov[t]);
            }
}

void dfs2(int x) {
    d2[x] = true;
    for (int t = fir[x]; t; t = nxt[t])
        if (!(t & 1))
            if (!d2[ tov[t] ]) {
                d2[ tov[t] ] = 1;
                if (f[ tov[t] ] != 1) dfs2(tov[t]);
            }
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
    }
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (f[i] == 1) dfs(i);
        if (f[i] == 2) dfs2(i);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (d1[i] && d2[i]) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    
    return 0;
}