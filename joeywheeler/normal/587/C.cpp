#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> v[17][100005];
int p[17][100005];
int d[100005];
vector<int> u[100005];
int n, m, q;

void merge(vector<int> &a, const vector<int> &b) {
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    if (sz(a) > 10) a.resize(10);
}

void go(int i) {
    for (int j : u[i]) if (j != p[0][i]) {
        p[0][j] = i;
        d[j] = d[i]+1;
        go(j);
    }
}

vector<int> calc(int a, int b) {
    //printf("calc %d,%d\n", a, b);
    vector<int> res;
    if (d[a] < d[b]) swap(a,b);
    for (int i = 16; i >= 0; i--) if (d[p[i][a]] >= d[b]) {
        merge(res, v[i][a]);
        a = p[i][a];
    }
    //printf("a=%d,b=%d\n", a, b);
    for (int i = 16; i >= 0; i--) if (p[i][a] != p[i][b]) {
        merge(res, v[i][a]);
        a = p[i][a];
        merge(res, v[i][b]);
        b = p[i][b];
    }
    while (a != b) {
        int i = 0;
        merge(res, v[i][a]);
        a = p[i][a];
        merge(res, v[i][b]);
        b = p[i][b];
    }
    merge(res, v[0][a]);
    //printf("lca=%d\n", a);
    return res;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    FO(i,0,n-1) {
        int x, y; scanf("%d%d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    FO(i,0,m) {
        int c; scanf("%d", &c);
        v[0][c].push_back(i+1);
    }
    FO(i,1,n+1) {
        merge(v[0][i], {});
    }
    d[1] = 1;
    go(1);
    FO(i,1,17) FO(j,1,n+1) {
        int mp = p[i-1][j];
        p[i][j] = p[i-1][mp];
        v[i][j] = v[i-1][j];
        merge(v[i][j], v[i-1][mp]);
    }
    FO(i,0,q) {
        int u, v, a; scanf("%d%d%d", &u, &v, &a);
        vector<int> r = calc(u,v);
        if (sz(r) > a) r.resize(a);
        printf("%d", sz(r));
        for (int x : r) printf(" %d", x);
        printf("\n");
    }
}