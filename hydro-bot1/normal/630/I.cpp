// Hydro submission #631f319332ae6c3198c91206@1662988691296
#include<bits/stdc++.h>
using namespace std;
long long quick_pow(int a,int b)
{
    if(!b) return 1;
    long long s=quick_pow(a,b/2);
    s=s*s;
    if(b%2) s=s*a;
    return s;
}
int main()
{
    int n;
    cin>>n;
    printf("%lld\n",quick_pow(4,n-3)*24+quick_pow(4,max(0,n-4))*(n-3)*36);
    return 0; 
}