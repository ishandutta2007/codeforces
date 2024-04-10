#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll n,k;
vector<int> a;
vector<int>ed[109];
ll dp[109][109];
ll cal(int x ,int z)
{
    if(z==0)return 1;
    if(z<0)return 0;
    if(x>=a.size())return 0;
    if(dp[x][z]!=-1)return dp[x][z];
    return dp[x][z]=(cal(x+1,z) + cal(x+1,z-1)*a[x])%mod;
}
ll go(int x,int pr,int lv,int u)
{
    if(lv==u)return 1;
    int ans=0;
    for(int i=0;i<ed[x].size();i++)
    {
        if(ed[x][i]==pr)continue;
        ans+=go(ed[x][i],x,lv+1,u);
    }
    return ans;
}
ll ch(int x,int len)
{
    ll ff=ed[x].size();
    if(ff<k)return 0;
    a.clear();
    for(int i=0;i<ed[x].size();i++)
        a.push_back(go(ed[x][i],x,1,len));
     for(int i=0;i<=a.size();i++)
         for(int j=0;j<=k;j++)dp[i][j]=-1;
    return cal(0,k);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)ed[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
       if(k==2)
       {
           cout<<n*(n-1)/2<<endl;continue;
       }
       ll ans=0;
       for(int len=1;len<n;len++)
        for(int i=1;i<=n;i++)
        {ans+=ch(i,len);ans%=mod;}
        cout<<ans<<endl;
    }
    return 0;
}