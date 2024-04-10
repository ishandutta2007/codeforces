#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> u[100005];
int a[100005];
int res = 0;
int n,m;

void go(int i, int p, int nm, int nc) {
    int leaf = 1;
    if (a[i]) nc++;
    else nc = 0;
    nm = max(nm,nc);
    for (int j : u[i]) if (j != p) {
        go(j,i,nm,nc);
        leaf = 0;
    }
    if (leaf) {
        res += nm <= m;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    FO(i,1,n+1) scanf("%d", a+i);
    FO(i,0,n-1) {
        int x,y; scanf("%d%d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    go(1,0,0,0);
    printf("%d\n", res);
}