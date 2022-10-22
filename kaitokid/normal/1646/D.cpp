#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//int lvl[200008];
vector<int>ed[200009];
/*void go(int x,int l,int p=0)
{
    lvl[x]=l;
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=p)go(ed[x][i],l+1,x);
}*/
pair<int,int> dp[200009][2];
int ans[2000009];
pair<int,int>mrg(pair<int,int> x,pair<int,int> y)
{
    return {x.first+y.first,x.second+y.second};
}
void go(int x,int p)
{
    //if(dp[x][u]!={-1,-1})return dp[x][u];
    int g=ed[x].size();
    dp[x][1]=make_pair(1,-g);
    dp[x][0]=make_pair(0,-1);
    for(int i=0;i<ed[x].size();i++)
    {
        if(ed[x][i]==p)continue;
            go(ed[x][i],x);
            int u=ed[x][i];
       dp[x][0]=mrg(dp[x][0],max(dp[u][1],dp[u][0]));
       dp[x][1]=mrg(dp[x][1],dp[u][0]);}
}
void cal(int x,int u,int p)
{
    if(u==0)ans[x]=1;
    else ans[x]=ed[x].size();
    if(u==1)
    {
        for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=p)cal(ed[x][i],0,x);
        return;
    }
    for(int i=0;i<ed[x].size();i++)
    {if(ed[x][i]==p)continue;
    int g=ed[x][i];
    if(dp[g][0]>dp[g][1])cal(g,0,x);
    else cal(g,1,x);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    if(n==2)
    {
        cout<<"2 2\n1 1";
        return 0;
    }
    go(1,0);
    if(dp[1][0]>dp[1][1])cal(1,0,0);
    else cal(1,1,0);
    pair<int,int>h=max(dp[1][0],dp[1][1]);
    cout<<h.first<<" "<<(-1*h.second)<<endl;
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}