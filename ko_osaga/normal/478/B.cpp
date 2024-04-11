#include <cstdio>

int main(){
    long long m,n;
    scanf("%I64d %I64d",&n,&m);
    long long maxV = (n-m)*(n-m+1)/2;
    long long numberOfBigOnes = n%m;
    long long numberOfSmallOnes = m - numberOfBigOnes;
    long long minV = numberOfBigOnes * (n/m+1) * (n/m) / 2 + numberOfSmallOnes * (n/m) * (n/m-1)/2;
    printf("%I64d %I64d",minV,maxV);
}