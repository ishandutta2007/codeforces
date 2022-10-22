#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll n,m,k,x,y;
ll pr[500009],a[500009],b[500009];
vector<ll>ans;
bool z[500009];
ll pw[500009],tot[500009],h[500009];
ll pa(ll x)
{
    if(pr[x]==x)return x;
    return pr[x]=pa(pr[x]);
}
int main()
{
    pw[0]=1;
    for(int i=1;i<500006;i++)pw[i]=(pw[i-1]*2)%mod;
    cin>>n>>m;
    for(int i=1;i<=m;i++)pr[i]=i;
    int v=0;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        if(k==1)
        {
            cin>>x;
         if(pa(x)==0)continue;
         pr[pa(x)]=0;

         ans.push_back(i);
        continue;
        }
        cin>>a[i]>>b[i];
       if(pa(b[i])==pa(a[i]))continue;
        ans.push_back(i);
        if(pa(a[i])==0)swap(a[i],b[i]);
        pr[pa(a[i])]=pa(b[i]);


    }

    ll res=1;
    for(int i=1;i<=m;i++)
    {
        ll u=pa(i);
        tot[u]++;
    }
    for(int i=1;i<=m;i++)
    {
        if(tot[i]==0)continue;
        ll p;  p=pw[tot[i]-1];
        //else p=pw[tot[i]];

        res=(res*p)%mod;

    }
    if(tot[0])res=(res*pw[tot[0]])%mod;
    cout<<res<<" "<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}