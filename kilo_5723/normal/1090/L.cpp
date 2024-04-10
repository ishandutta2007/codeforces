#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t,n,a,b,k;

int main()
{
    cin>>t>>n>>a>>b>>k;
    if (k>n) {puts("0");return 0;}
    LL x=(n+1LL)/2LL,y=n/2LL;
    LL ans=(a*x+b*y)/k;
    if (k-y>0) ans=min(ans,a*x/(k-y));
    if (k-x>0) ans=min(ans,b*y/(k-x));
    ans=min(ans,t);
    cout<<ans<<endl;
    return 0;
}