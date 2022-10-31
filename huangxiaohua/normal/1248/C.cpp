#include<stdio.h>
long long int f[100001],i,m,n;main(){f[1]=1;f[2]=2;for(i=3;i<=100000;i++){f[i]=(f[i-1]+f[i-2])%1000000007;}scanf("%lld%lld",&m,&n);printf("%lld",2*(f[m]+f[n]-1)%1000000007);}