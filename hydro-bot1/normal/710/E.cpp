// Hydro submission #61891c7d1edf93b3ad658902@1636375678496
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Min(x,y) (x<y?x:y)
int n,x,y,f[10000010];
signed main() {
    scanf("%lld%lld%lld",&n,&x,&y);
    f[1]=x;
    for (int i=2;i<=n;i++) {
        if (i%2==0) f[i]=Min(f[i-1]+x,f[i/2]+y);
        else f[i]=Min(f[i-1]+x,f[(i+1)/2]+x+y);
    }
    printf("%lld\n",f[n]);
    return 0;
}