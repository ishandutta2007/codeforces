#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
vector<int> u[300005];
set<int> nu[300005];
int xr[300005];
int l[300005];

int gl(int i) {
    if (l[i] == i) return i;
    else return l[i] = gl(l[i]);
}

int cv;
int vls[300005];

void go(int i) {
    vls[i] = ++cv;
    for (int j : nu[i]) if (vls[j] == 0) {
        go(j);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    FO(i,1,n+1) l[i] = i;
    FO(i,0,m) {
        int x, v; scanf("%d %d", &x, &v);
        u[x].push_back(v);
        u[v].push_back(x);
        xr[x] ^= v;
        xr[v] ^= x;
    }
    FO(i,1,n+1) {
        xr[i] ^= i;
        u[i].push_back(i);
        sort(u[i].begin(), u[i].end());
    }
    FO(i,1,n+1) for (int j : u[i]) {
        if (xr[i] == xr[j] && sz(u[i]) == sz(u[j]) && u[i] == u[j]) {
            l[gl(i)] = gl(j);
        }
    }
    FO(i,1,n+1) {
        for (int j : u[i]) if (gl(j) != gl(i)) {
            nu[gl(i)].insert(gl(j));
            nu[gl(j)].insert(gl(i));
        }
    }
    FO(i,1,n+1) if (sz(nu[i]) > 2) {
        printf("NO\n");
        return 0;
    }

    FO(i,1,n+1) if (gl(i) == i && vls[i]==0 && sz(nu[i]) <= 1) {
        go(i);
        cv += 5;
    }
    FO(i,1,n+1) if (gl(i) == i && vls[i]==0) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    FO(i,1,n+1) {
        printf("%d%c", vls[gl(i)], " \n"[i==n]);
    }
}