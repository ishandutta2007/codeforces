#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int n,m;
ll a[N],b[N],ha[N],hb[N];
vector<int>vc[N];
unordered_map<int,ll>mp;
unordered_map<int,ll>::iterator it;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),vc[i].clear(),b[i]=ha[i]=hb[i]=0;
        for(int i=1;i<=m;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            b[u]+=a[v];
            vc[v].push_back(u);
            hb[u]^=v*23333;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vc[i].size()) continue;
            for(int x:vc[i]) ha[i]^=hb[x];
            mp[ha[i]]+=a[i];
        }
        ll ans=0;
        for(it=mp.begin();it!=mp.end();it++)
            ans=__gcd(ans,it->second);
        for(int i=1;i<=n;i++) ans=__gcd(ans,b[i]);
        printf("%lld\n",ans);
    }
}