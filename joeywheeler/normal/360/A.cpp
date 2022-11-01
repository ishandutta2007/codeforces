#include <bits/stdc++.h>

using namespace std;
int a[5005];
int d[5005];
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) a[i] = 1e9;
    for (int i = 0; i < m; i++) {
        int t,l,r,v; scanf("%d%d%d%d", &t, &l, &r, &v);
        if(t==1)for (int j = l-1; j < r; j++) d[j] += v;
        else for (int j = l-1; j < r; j++) a[j] = min(a[j],v-d[j]);
    }
    rewind(stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) d[i] = 0;
    for (int i = 0; i < m; i++) {
        int t,l,r,v; scanf("%d%d%d%d", &t, &l, &r, &v);
        int x = -1e9;
        if(t==1)for (int j = l-1; j < r; j++) d[j] += v;
        else {
            for (int j = l-1; j < r; j++) x = max(x,a[j]+d[j]);
            if (x != v) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}