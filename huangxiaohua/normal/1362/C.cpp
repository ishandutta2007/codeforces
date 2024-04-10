#include<stdio.h>
long long i,n,t,r;main(){scanf("%lld",&n);while(n--){r=0;scanf("%lld",&t);for(i=1;i<=t;i*=2){r+=t/i;}printf("%lld\n",r);}}