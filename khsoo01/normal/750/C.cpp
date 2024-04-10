#include<bits/stdc++.h>
const int inf = 1e9;
using namespace std;
int n, a[200005], b[200005];
int s = -inf, e = inf;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int i=1;i<=n;i++) {
        if(b[i] == 1) s = max(s, 1900);
        else e = min(e, 1899);
        s += a[i]; e += a[i];
    }
    if(s>e) {puts("Impossible"); return 0;}
    if(e > 1e8) {puts("Infinity"); return 0;}
    printf("%d\n",e);
}