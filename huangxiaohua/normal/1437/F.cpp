#include<bits/stdc++.h>
using namespace std;
#define M 998244353
#define N 5050
long long b[N],d[N],s[N],u[N],p;int n,i,j,k;main(){scanf("%d",&n);for(i=1;i<=n;i++){scanf("%lld",&b[i]);}sort(b+1,b+n+1);for(i=n,j=n;i>=1;i--){d[i]=1;for(;j>=1;j--){if(b[j]*2<=b[i]){u[i]=j;break;}}u[i]+=2;}for(i=2;i<=n;i++){for(j=1;j<=n;j++){p=d[j];d[j]=(p*max(u[j]-i,0ll)+s[u[j]-2])%M;s[j]=s[j-1]+p;}}printf("%lld",d[n]);}