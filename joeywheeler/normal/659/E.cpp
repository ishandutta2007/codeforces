#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int l[100005];
int ne[100005];
int nv[100005];
int n, m;

int gl(int i) {
    return i == l[i] ? i : l[i]=gl(l[i]);
}

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,n) {
        l[i] = i;
        ne[i] = 0;
        nv[i] = 1;
    }
    FO(i,0,m) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        x = gl(x); y = gl(y);
        if (x == y) {
            ne[x]++;
        } else {
            ne[x] += ne[y]+1;
            nv[x] += nv[y];
            l[y] = x;
        }
    }
    int res = 0;
    FO(i,0,n) if (i == l[i]) {
        if (ne[i]+1 == nv[i]) res++;
    }
    printf("%d\n", res);
}