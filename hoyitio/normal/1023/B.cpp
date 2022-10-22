#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    long long ans;
    ans = (k-1)/2;
    if(n<k-1){
        ans  -= (k-n-1);
    }
    if(ans<0)ans = 0;
    printf("%I64d",ans);
    return 0;
}