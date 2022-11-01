#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+5;
int n,f[N],ans[N];
bool vis[N];
ll a[N];
map<int,int>mp;
void getans()
{
    for(int i=0;i<=30;i++) ans[i]=0;
    map<int,int>mp2;
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
       ans[0]=max(ans[0],it->second);
       if(it->first==1||it->second%2==0) mp2[1]+=it->second;
       else mp2[it->first]+=it->second;
    }
    for(map<int,int>::iterator it=mp2.begin();it!=mp2.end();it++)
       ans[1]=max(ans[1],it->second);
}
int main()
{
    for(int i=1;i<=3000000;i++) f[i]=1;
    for(int i=2;i<=3000000;i++)
        if(!vis[i])
        {
            for(int j=i;j<=3000000;j+=i)
            {
                vis[j]=true;
                int k=0,x=j;
                while(x%i==0) x/=i,k^=1;
                if(k) f[j]=f[j]*i;
            }
        }
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);a[i]=f[a[i]];
            mp[a[i]]++;
        }
        getans();
        int q;scanf("%d",&q);
        while(q--)
        {
            ll k;scanf("%lld",&k);
            printf("%d\n",ans[min(k,1ll)]);
        }
    }
}