#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
vector<int> v[6005];
int r[6005];
int dirof[6005][6005];
int root;

void dfs(int p, int i, int own=-1) {
    dirof[root][i] = own;
    FO(j,0,sz(v[i])) if (v[i][j] != p) {
        dfs(i, v[i][j], own == -1 ? v[i][j] : own);
    }
}

map<int,int> cache[6005];
int dp(int cur, int par) {
    if (cache[cur].find(par) != cache[cur].end()) return cache[cur][par];
    int res = 1;
    FO(i,0,n) if (i != cur && dirof[cur][i] != par && r[i] > r[cur]) {
        res = max(res, 1 + dp(i, dirof[i][cur]));
    }
    return cache[cur][par] = res;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", r+i);
    }
    FO(i,0,n-1) {
        int a,b; scanf("%d%d", &a,&b); a--; b--;
        v[a].push_back(b); v[b].push_back(a);
    }
    FO(i,0,n) {
        root = i;
        dfs(-1,i);
    }
    int res = 1;
    FO(i,0,n) FO(j,0,sz(v[i])) {
        res = max(res, dp(i,-1));
    }
    printf("%d\n", res);
}