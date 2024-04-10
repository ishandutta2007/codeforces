#include<stdio.h>

long long t=1,s=1,n,m=1000000007;

int main(){
    scanf("%I64d",&n);
    for(int i=0;i<3*n;i++)t*=3,t%=m;
    for(int i=0;i<n;i++)s*=7,s%=m;
    printf("%I64d",(t-s+2*m)%m);
}