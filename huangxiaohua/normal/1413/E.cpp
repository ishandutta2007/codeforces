#include<stdio.h>
int t;long long a,b,c,d;
main(){scanf("%d",&t);while(t--){scanf("%lld%lld%lld%lld",&a,&b,&c,&d);if(a>(b*c)){puts("-1");continue;}printf("%lld\n",(a/b/d+1)*a-(a/b/d+1)*(a/b/d)*d/2*b);}}