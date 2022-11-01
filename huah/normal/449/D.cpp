#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7,N=2e6+5;
int n;
ll f[N],p2[N];
void dp(int s)
{
    for(int i=0;i<=19;i++)
        for(int j=n;j>=0;j--)
        if(!((j>>i)&1))
            (f[j]+=f[j|(1<<i)]*s)%=mod;
}
int main()
{
    p2[0]=1;
    for(int i=1;i<N;i++) p2[i]=p2[i-1]*2%mod;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);f[x]++;
    }
    n=(1<<20)-1;
    dp(1);
    for(int i=0;i<=n;i++) f[i]=p2[f[i]]-1;
    dp(-1);
    printf("%lld\n",(f[0]+mod)%mod);
}