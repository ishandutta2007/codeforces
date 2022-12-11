#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 150010;

int n, cnt, f[N];
int L[N], R[N], l[N], r[N];

int fd(int u) {
    return u == f[u] ? u : f[u] = fd(f[u]);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) f[i] = l[i] = r[i] = i, L[i] = R[i] = 0;
    for(int x, y, i = 1; i < n; i ++) {
        scanf("%d%d", &x, &y);
        int a = fd(x), b = fd(y);
        f[b] = a;
        R[r[a]] = l[b];
        L[l[b]] = r[a];
        r[a] = r[b];
    }
    int st = 0;
    for(int i = 1; i <= n; i ++)
        if(!L[i]) st = i;
    while(st) {
        printf("%d ", st);
        st = R[st];
    }
    return 0;
}