#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=2e5+5;
int a[maxn],dp1[maxn],dp2[maxn],dp3[maxn];
int main(){
    int i,p,q,r,n,t;
    scanf("%d%d%d",&p,&q,&r); n=p+q+r;
    for (i=0;i<p;i++){ scanf("%d",&t); a[t]=1; }
    for (i=0;i<q;i++){ scanf("%d",&t); a[t]=2; }
    for (i=0;i<r;i++){ scanf("%d",&t); a[t]=3; }
    for (i=1;i<=n;i++){
        dp1[i]=dp1[i-1]+(a[i]!=1);
        dp2[i]=dp2[i-1]+(a[i]!=2);
        dp3[i]=dp3[i-1]+(a[i]!=3);
        dp2[i]=min(dp2[i],dp1[i]);
        dp3[i]=min(dp3[i],dp2[i]);
    }
    printf("%d\n",min(min(dp1[n],dp2[n]),dp3[n]));
    return 0;
}