#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
const ll mod=998244353;
int main()
{
    int w,h;
    ll ans=1;
    scanf("%d%d",&w,&h);
    for(int i=0;i<w+h;i++)ans=ans*2%mod;
    printf("%lld",ans);
}