#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, a[N], r;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0, x, y, z; i < m; i++){
        scanf("%d%d%d", &x, &y, &z);
        a[x] += z;
        a[y] -= z;
    }
    for(int i = 1; i <= n; i++) r += max(0, a[i]);
    printf("%d\n", r);
}