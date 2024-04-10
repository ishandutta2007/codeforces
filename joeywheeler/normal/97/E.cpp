#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
vector<int> u[100005];
vector<int> v[100005];
int cid[100005], _CID, col[100005], d[100005], par[100005], SPEC[100005], spec[100005];
int P[18][100005], Q[18][100005];
set<int> mergeto;
int l[100005];

int gl(int a) {
    return l[a]=a==l[a]?a:gl(l[a]);
}

void dfs(int i, int p, int _d=1) {
    col[i] = col[p]^1;
    cid[i] = _CID;
    d[i] = _d++;
    par[i] = p;
    FO(j,0,sz(u[i])) if (cid[u[i][j]] == 0) {
        v[i].push_back(u[i][j]); dfs(u[i][j],i,_d);
    }
    FO(j,0,sz(u[i])) if (d[u[i][j]] < d[i]) {
        int to = d[u[i][j]]+1;
        for (int x = i; d[x] > to; x = gl(x)) {
            l[gl(x)] = gl(par[x]);
        }
    }
}

int lca(int i, int j) {
    if (d[i] < d[j]) swap(i,j);
    int r = 0;
    for (int k=17;k>=0;k--) if (d[P[k][i]]>=d[j]) {
        r += Q[k][i];
        i = P[k][i];
    }
    if (i == j) return r;
    for (int k=17;k>=0;k--) if (P[k][i]!=P[k][j]) {
        r += Q[k][i]+Q[k][j];
        i = P[k][i]; j = P[k][j];
    }
    return r+Q[0][i]+Q[0][j];
}

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,m) {
        int a,b; scanf("%d%d", &a, &b);
        u[a].push_back(b); u[b].push_back(a);
    }
    FO(i,1,n+1) l[i] = i;
    FO(i,1,n+1) if (cid[i]==0) _CID++, dfs(i,0);
    FO(i,1,n+1) FO(j,0,sz(u[i])) {
        if (col[i]==col[u[i][j]]) {
            int lo = d[i]<d[u[i][j]] ? u[i][j] : i;
            SPEC[gl(lo)] = true;
        }
    }
    FO(i,1,n+1) if (SPEC[gl(i)]) spec[i] = true;

    FO(i,1,n+1) P[0][i] = par[i], Q[0][i] = spec[i];
    FO(i,1,18) FO(j,1,n+1) {
        Q[i][j] = Q[i-1][j] + Q[i-1][P[i-1][j]];
        P[i][j] = P[i-1][P[i-1][j]];
    }
    int q; scanf("%d", &q);
    FO(_,0,q) {
        int s, t; scanf("%d %d", &s, &t);
        if (cid[s] != cid[t] || s == t) {
            printf("No\n");
            continue;
        }
        if (col[s] != col[t]) {
            printf("Yes\n");
            continue;
        }
        printf(lca(s,t) ? "Yes\n" : "No\n");
    }
}