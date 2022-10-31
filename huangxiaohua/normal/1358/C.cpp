#include<stdio.h>
long long n,a,b,c,d,i=1;main(){scanf("%d",&n);for(;i<=n;i++){scanf("%d%d%d%d",&a,&b,&c,&d);printf("%lld\n",(c-a)*(d-b)+1);}}