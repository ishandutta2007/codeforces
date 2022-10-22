#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,g,r;
ll wh[10009];
ll vis[10009][1009];
int main()
{
ios::sync_with_stdio(0);
cin>>n>>m;
for(int i=1;i<=m;i++)
{cin>>wh[i];}
sort(wh+1,wh+m+1);

cin>>g>>r;


deque<pair<ll,ll> >q;

memset(vis,-1,sizeof vis);
 vis[1][0]=0;

 q.push_back({1,0});
 while(!q.empty())
 {
     ll u=q.front().first;
     ll v=q.front().second;
    q.pop_front();
    if(v==g){vis[u][0]=vis[u][g]+1;q.push_back({u,0});continue;}
if(u>1)
{
    ll s=v+wh[u]-wh[u-1];
    if(s<=g&&vis[u-1][s]==-1){vis[u-1][s]=vis[u][v];q.push_front({u-1,s});}
}
if(u<m)
{
    ll s=v+wh[u+1]-wh[u];
    if(s<=g&&vis[u+1][s]==-1){vis[u+1][s]=vis[u][v];q.push_front({u+1,s});}
}
 }
 ll ans=-1;
 for(int i=1;i<=m;i++)
 {
     if(n-wh[i]>g)continue;
     if(vis[i][0]==-1)continue;
     ll res=(r+g)*vis[i][0]+(n-wh[i]);
     if(ans==-1)ans=res;
     ans=min(ans,res);
 }
 cout<<ans;
    return 0;
}