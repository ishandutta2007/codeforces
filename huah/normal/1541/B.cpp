#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long ll;
//typedef __int128 ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=2e5+5,mod=998244353,G=3,Gi=332748118;
int t,pos[N];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=2*n;i++) pos[i]=0;
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);pos[x]=i;
        }
        int ans=0;
        for(int i=1;i<=2*n;i++)
            for(int j=i+1;1ll*i*j<=2*n;j++)
            if(pos[i]&&pos[j])
            ans+=i*j==pos[i]+pos[j];
        printf("%d\n",ans);
    }
}