#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>num[400009],mx[400009];
string s[400009];
vector<int>ed[400009];
int dfsnum[400009],dfslow[400009],com[400009],id,cm;
bool vis[400008];
stack <int>st;
int inn[400009];
void dfs(int x)
{
    dfsnum[x]=dfslow[x]=++id;
    vis[x]=true;
    st.push(x);
    for(int i=0;i<ed[x].size();i++)
    {
        int u=ed[x][i];
        if(!dfsnum[u])dfs(u);
        if(vis[u])dfslow[x]=min(dfslow[x],dfslow[u]);
    }
    if(dfslow[x]==dfsnum[x])
    {
        com[x]=cm;
        vis[x]=0;
        while(st.top()!=x){com[st.top()]=cm;vis[st.top()]=0;st.pop();}
        st.pop();
        cm++;
    }

}

int n,m,r=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {cin>>s[i];
    for(int j=0;j<m;j++){
            mx[i].push_back(0);
            if(s[i][j]=='.')num[i].push_back(0);else {num[i].push_back(++r);mx[i][j]=r;} }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<m;j++)if(mx[i][j]==0)mx[i][j]=mx[i+1][j];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        if(s[i][j]=='.')continue;
        if((i!=(n-1))&&(mx[i+1][j]!=0))ed[num[i][j]].push_back(mx[i+1][j]);
        if((j!=0)&& (mx[i][j-1]!=0))ed[num[i][j]].push_back(mx[i][j-1]);
        if((j!=(m-1))&& (mx[i][j+1]!=0))ed[num[i][j]].push_back(mx[i][j+1]);
        if((i!=0)&&(num[i-1][j]!=0))ed[num[i][j]].push_back(num[i-1][j]);
    }
    for(int i=1;i<=r;i++)
        if(!dfsnum[i])dfs(i);
    for(int i=1;i<=r;i++)
    {
       // cout<<r<<" "<<i<<" "<<com[i]<<endl;
        for(int j=0;j<ed[i].size();j++)if(com[i]!=com[ed[i][j]])inn[com[ed[i][j]]]++;
    }
    int ans=0;
    for(int i=0;i<cm;i++)
        if(inn[i]==0)ans++;
    cout<<ans<<endl;
    int zz;
    for(int i=0;i<m;i++)
        cin>>zz;
    return 0;
}