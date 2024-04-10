#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,dp[1000009][2],num,gg;
vector<int>ed[1000009];
int vis[1000009];
int uu[1000009];
bool tmp[1000009];
int ans1,ans2;
int res[1000009];
void go(int x,int p,int k)
{
    vis[x]=k;
    uu[x]=1;
    for(int i=0;i<ed[x].size();i++)
    {
        if(ed[x][i]==p)continue;
        int u=ed[x][i];
        if(uu[u]==2)continue;
        if(uu[u]==0){go(u,x,k+1);continue;}
        if((vis[u]%2) ==(k%2)){num++;dp[x][1]++;dp[u][1]--;gg=x;}
        else dp[x][0]++,dp[u][0]--;
    }
    uu[x]=2;


}
void cal(int x,int p)
{
    tmp[x]=1;
    if(ans1!=-1)return;
    for(int i=0;i<ed[x].size();i++)
    {
         if(ed[x][i]==p)continue;
         int u=ed[x][i];
         if(tmp[u]==1)continue;
         cal(u,x);
         if(ans1!=-1)continue;
         dp[x][0]+=dp[u][0];
         dp[x][1]+=dp[u][1];
    }
    if(dp[x][0]==0 && dp[x][1]==num){ans1=x;ans2=p;return;}
}
void rn(int x,int p,int z)
{
    res[x]=z;
    tmp[x]=1;
    for(int i=0;i<ed[x].size();i++)
    {
        int u=ed[x][i];
        if(u==p || tmp[u])continue;
        if(ans1==u)rn(u,x,z);
        else rn(u,x,1-z);
    }


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        num=0;
        ans1=ans2=-1;
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
            tmp[i]=0;
            uu[i]=0;
            dp[i][1]=dp[i][0]=0;
            ed[i].clear();
        }
        int x,y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            ed[x].push_back(y);
            ed[y].push_back(x);

        }

        go(1,0,1);
        if(num>1)
        cal(1,0);
        else ans1=1;
        if(ans1==-1){cout<<"NO"<<endl;continue;}
        for(int i=1;i<=n;i++)tmp[i]=0;
        rn(1,0,0);
        cout<<"YES"<<endl;
        if(res[ans1]==0)
            for(int i=1;i<=n;i++)res[i]=1-res[i];
        if(num==1 && res[gg]==0)
            for(int i=1;i<=n;i++)res[i]=1-res[i];
        for(int i=1;i<=n;i++)cout<<res[i];
        cout<<endl;
    }
    return 0;
}