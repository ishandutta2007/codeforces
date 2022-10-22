#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,m,a,b,c;
vector<int>v[200009];
ll p[200009];
int vis1[200009],vis2[200009],vis3[200009];
int main()
{

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>a>>b>>c;
for(int i=1;i<=n;i++){v[i].clear();vis1[i]=-1,vis2[i]=-1;vis3[i]=-1;}
for(int i=0;i<m;i++)cin>>p[i];
sort(p,p+m);
for(int i=1;i<m;i++)p[i]+=p[i-1];
int x,y;
for(int i=0;i<m;i++){cin>>x>>y;v[x].push_back(y);v[y].push_back(x);}
queue<int> q;
vis1[a]=0;
vis2[b]=0;
vis3[c]=0;
q.push(a);
while(!q.empty())
{int u=q.front();
q.pop();
for(int i=0;i<v[u].size();i++){if(vis1[v[u][i]]!=-1)continue;vis1[v[u][i]]=vis1[u]+1;q.push(v[u][i]);}}
q.push(b);
while(!q.empty())
{int u=q.front();
q.pop();
for(int i=0;i<v[u].size();i++){if(vis2[v[u][i]]!=-1)continue;vis2[v[u][i]]=vis2[u]+1;q.push(v[u][i]);}}
q.push(c);
while(!q.empty())
{int u=q.front();
q.pop();
for(int i=0;i<v[u].size();i++){if(vis3[v[u][i]]!=-1)continue;vis3[v[u][i]]=vis3[u]+1;q.push(v[u][i]);}}
ll ans=1e18;
    for(int i=1;i<=n;i++)
    {
        ll k=vis1[i]+vis2[i]+vis3[i];
    if(k>m)continue;
    ll res=p[k-1]+p[vis2[i]-1];
    ans=min(ans,res);
    }
 cout<<ans<<endl;
    }

    return 0;
}