#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    unsigned long long n,i,a,b,k;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld%lld",&a,&b);
        k=cbrt(a*b);
        if((k+1)*(k+1)*(k+1)==a*b)k++;
        else if((k-1)*(k-1)*(k-1)==a*b)k--;
        if(k*k*k==a*b && a%k==0 && b%k==0)puts("Yes");
        else puts("No");
    }
    return 0;
}