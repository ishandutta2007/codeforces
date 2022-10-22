#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[200009];
vector<int>ed[200009];
map<int,int>mp;
int ans=0;
bool gg[200009];
int sz[200009],f[200009],ch[200009];
void dfs(int x,int p)
{
    f[x]=a[x]^f[p];
    sz[x]=1;
    for(int i=0;i<ed[x].size();i++)
    if(ed[x][i]!=p){dfs(ed[x][i],x);sz[x]+=sz[ed[x][i]];if(sz[ed[x][i]]>sz[ch[x]])ch[x]=ed[x][i];}

}
void hh(int x,int p,int r)
{
    if(gg[x])return;
    if((mp[a[r]^f[x]] ) ){gg[r]=true;return;}
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=p)hh(ed[x][i],x,r);
}
void add(int x,int p)
{
    if(gg[x])return;
    mp[f[x]]=true;
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=p)add(ed[x][i],x);
}
void go(int x,int p,bool sv)
{
    for(int i=0;i<ed[x].size();i++)
    {
        if(ed[x][i]==p)continue;
        if(ed[x][i]==ch[x])continue;
        go(ed[x][i],x,0);
    }
    if(ch[x]!=0)go(ch[x],x,1);
      for(int i=0;i<ed[x].size();i++)
    {
        if(ed[x][i]==p)continue;
        if(ed[x][i]==ch[x])continue;
        hh(ed[x][i],x,x);
        add(ed[x][i],x);
    }
    if(mp[f[x]^a[x]])gg[x]=true;
    if((sv==0)||(gg[x]==true)){mp.clear();return;}
    mp[f[x]]=true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    dfs(1,0);
    go(1,0,0);

    int ans=0;
    for(int i=1;i<=n;i++)if(gg[i])ans++;
    cout<<ans<<endl;
    return 0;
}