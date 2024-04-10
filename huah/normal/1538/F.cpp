#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long ll;
//typedef __int128 ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=1e5+5,mod=998244353,G=3,Gi=332748118;
int t,n;
ll sol(int n)
{
    ll ans=0;
    while(n) ans+=n,n/=10;
    return ans;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int l,r;scanf("%d%d",&l,&r);
        printf("%lld\n",sol(r)-sol(l));
    }
}