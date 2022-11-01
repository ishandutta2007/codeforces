#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct e {
    int a, b;
    int l;
    int i;
};

int n, q;
int v[100005];
double pr[100005];
int len[100005];
vector<e> adj[100005];

int f(int a, int p) {
    int me = 1;
    FO(i,0,sz(adj[a])) if (adj[a][i].i != p) {
        me += f(adj[a][i].b, adj[a][i].i);
    }
    if (p != -1) v[p] = me;
    return me;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n-1) {
        int a,b,l; scanf("%d%d%d", &a, &b, &l); a--; b--;
        len[i] = l;
        e E; E.a = a; E.b = b; E.l = l; E.i = i;
        adj[a].push_back(E);
        E.a = b; E.b = a; E.l = l;
        adj[b].push_back(E);
    }
    f(0,-1);
    double cur = 0;
    FO(i,0,n-1) {
        double a = v[i], b = n-v[i];
        pr[i] = (a / n) * (b / (n-1)) + (b / n) * (a / (n-1));
        cur += pr[i] * len[i];
    }

    scanf("%d", &q);
    FO(Z,0,q) {
        int i, l; scanf("%d%d", &i, &l); i--;
        cur -= pr[i] * len[i];
        len[i] = l;
        cur += pr[i] * len[i];
        printf("%.10lf\n", 3*cur);
    }
}