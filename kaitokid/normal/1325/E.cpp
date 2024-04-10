#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,ans=-1;
int pr[1000009],e[1000009];
vector<int>v[1000009];
int vis[1000009];
void go(int x)
{
    memset(vis,-1,sizeof vis);
    queue<pair<int,int> >q;
    q.push({0,x});
    while(!q.empty())
    {
        int u=q.front().first;
        int w=q.front().second;
        q.pop();
        if(vis[w]!=-1){if(ans==-1)ans=vis[u]+vis[w]+1;else ans=min(ans,vis[u]+vis[w]+1);continue;}
        vis[w]=vis[u]+1;
        for(int i=0;i<v[w].size();i++)
        if(v[w][i]!=u)q.push({w,v[w][i]});
    }

        }
int main()
{
    ios::sync_with_stdio(0);
for(int i=2;i<1009;i++)
{
    if(pr[i]>0)continue;
    for(int j=i*i;j<=1000000;j+=i)pr[j]=i;
}
cin>>n;
int x;
for(int i=0;i<n;i++)
{
    cin>>x;
    int u=pr[x];
    if(u==0){u=x;}
    int c=0;
 if(u!=1)   while(x%u==0){c++;x/=u;}
    if(c%2==0)u=1;
    int w=pr[x];
    if(w==0){w=x;}
    c=0;
    if(w!=1)while(x%w==0){c++;x/=w;}
    if(c%2==0)w=1;
  //cout<<u<<" "<<w<<endl;
    v[u].push_back(w);
    v[w].push_back(u);
    if(u*w==1){cout<<1;return 0;}
    if(e[u*w]==1){if(ans==-1)ans=2; else ans=min(ans,2);}
    e[u*w]++;
}
memset(vis,-1,sizeof vis);
for(int i=1;i<1000;i++)
{
    if(v[i].size()>0)go(i);
}
cout<<ans;
    return 0;
}