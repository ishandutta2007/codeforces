#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    long long ans=a/c+b/c,res=0;
    if(a%c+b%c>=c) ans++,res=min(c-a%c,c-b%c);
    printf("%lld %lld\n",ans,res);
}