#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define ll long long
int main(){
    int n, r, d, ri, xi, yi;
    sd(r); sd(d); sd(n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        sd(xi); sd(yi); sd(ri);
        if(ri > r) continue;
        if(r - d + ri > r - ri) continue;
        int p = xi * xi + yi * yi;
        if(p >= (r - d + ri) * (r - d + ri) && p <= (r - ri) * (r - ri)) ans++;
    }
    printf("%d\n", ans);
}