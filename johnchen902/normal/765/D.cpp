#include <cstdio>
#include <cstring>
using namespace std;
int f[100000], g[100000], h[100000];
int solve(int n) {
    for(int i = 0; i < n; i++)
        if(f[f[i]] != f[i])
            return 0;
    int m = 0; 
    for(int i = 0; i < n; i++) {
        if(i == f[i]) {
            h[m] = i;
            g[i] = m;
            m++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i != f[i]) {
            g[i] = g[f[i]];
        }
    }
    return m;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", f + i);
        f[i]--;
    }
    if(int m = solve(n)) {
        printf("%d\n", m);
        for(int i = 0; i < n; i++)
            printf("%d%c", g[i] + 1, i == n - 1 ? '\n' : ' ');
        for(int i = 0; i < m; i++)
            printf("%d%c", h[i] + 1, i == m - 1 ? '\n' : ' ');
    } else {
        puts("-1");
    }
}