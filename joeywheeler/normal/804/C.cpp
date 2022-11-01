#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
vector<int> u[300005];
set<int> c[300005];

int f[300005];
set<int> av;

void go(int i, int p) {
    for (int j : c[i]) {
        if (c[p].count(j)) {
            av.erase(f[j]);
        }
    }
    for (int j : c[i]) {
        if (!c[p].count(j)) {
            f[j] = *av.begin();
            av.erase(f[j]);
        }
    }
    for (int j : c[i]) {
        av.insert(f[j]);
    }
    for (int j : u[i]) if (j != p) go(j, i);
}

int main() {
    scanf("%d %d", &n, &m);
    int ms = 1;
    FO(i,1,n+1) {
        int s;
        scanf("%d", &s);
        ms = max(ms, s);
        FO(j,0,s) {
            int x; scanf("%d", &x);
            c[i].insert(x);
        }
    }
    FO(i,1,ms+1) av.insert(i);
    FO(i,0,n-1) {
        int x, y; scanf("%d %d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    go(1,0);
    printf("%d\n", ms);
    FO(i,1,m+1) {
        if (f[i] == 0) f[i] = 1;
        printf("%d%c", f[i], " \n"[i==m]);
    }
}