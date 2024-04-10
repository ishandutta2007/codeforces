#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>f[200009];
vector<int>ed[200009];
int vis[200009];
bool ans;
void go(int x,int u)
{
    if(vis[x]!=-1)
    {
        if(vis[x]==u)return;
       ans=false;
       return;
    }
   vis[x]=u;
   for(int i=0;i<ed[x].size();i++)
        if(vis[ed[x][i]]!=(1-u))go(ed[x][i],1-u);
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)f[i].clear();
     ans=true;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)ans=false;
        f[x].push_back(i);
        f[y].push_back(i);

    }
    for(int i=1;i<=n;i++)if(f[i].size()!=2)ans=false;
    if(!ans){cout<<"NO"<<endl;continue;}
    for(int i=1;i<=n;i++){ed[i].clear();vis[i]=-1;}
    for(int i=1;i<=n;i++){ed[f[i][0]].push_back(f[i][1]);ed[f[i][1]].push_back(f[i][0]);}
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==-1)go(i,0);
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
return 0;
}