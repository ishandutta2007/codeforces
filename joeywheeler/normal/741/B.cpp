#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = a; i < b; i++)

using namespace std;

int l[1005];
int n, m, mw;
int w[1005], b[1005];
vector<pair<int,int> > u[1005];

int gl(int i) {
    return i == l[i] ? i : l[i] = gl(l[i]);
}

pair<int,int> q[2005];
int f[2005][1005];
int t[2005];
int o;

int dp(int i, int j) {
    if (j < 0) return -2e9;
    else if (i == -1) return 0;
    else {
        int &res = f[i][j];
        if (res != -1) return res;
        res = dp(i-1, j);
        res = max(res, dp(t[i], j-q[i].first)+q[i].second);
        return res;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &mw);
    FO(i,0,n) scanf("%d", w+i);
    FO(i,0,n) scanf("%d", b+i);
    FO(i,0,n) l[i] = i;
    FO(i,0,m) {
        int x, y; scanf("%d %d", &x, &y); x--; y--;
        x = gl(x); y = gl(y);
        l[x] = y;
    }
    FO(i,0,n) u[gl(i)].emplace_back(w[i],b[i]);
    FO(i,0,n) if (l[i] == i) {
        int sw = 0;
        int sb = 0;
        for (auto p : u[i]) sw += p.first, sb += p.second;
        u[i].emplace_back(sw,sb);

        int f = o;
        for (auto p : u[i]) {
            q[o] = p;
            t[o] = f-1;
            o++;
        }
    }
    memset(f,-1,sizeof f);
    printf("%d\n", dp(o-1, mw));
}