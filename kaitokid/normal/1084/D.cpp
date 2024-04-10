#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
bool vis[300009];
ll w[300009];
vector<pair<int,ll> > a[300009];
ll ans=0;

ll go(int x)
{
vis[x]=true;
ll m1=0,m2=0;
for(int i=0;i<a[x].size();i++)
{if(vis[a[x][i].first])continue;
ll d=go(a[x][i].first)-a[x][i].second;

ll z=min(m1,d);
m1=max(m1,d);
m2=max(z,m2);


}
ll p=m1+m2+w[x];
ans=max(ans,p);
return m1+w[x];

}
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++)
cin>>w[i];
int x,y,z;
for(int i=1;i<n;i++){
cin>>x>>y>>z;
a[x].push_back(make_pair(y,z));
a[y].push_back(make_pair(x,z));}
go(1);
cout<<ans;
    return 0;
}