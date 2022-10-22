#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
pair<ll,ll>p[300009];
ll f[300009],ans[300009];
bool cmp(ll x,ll y)
{
    return p[x].second-p[x].first<p[y].second-p[y].first;
}
int main()
{ios::sync_with_stdio(0);
cin>>n>>m;
ll z=0,h=0;
for(int i=0;i<n;i++)
{
    f[i]=i;
   cin>>p[i].first>>p[i].second;
   z+=p[i].first;
}
sort(f,f+n,cmp);
for(int i=0;i<n;i++)
{
    int u=f[i];

    z-=p[u].first;
    //cout<<u<<" "<<z<<" "<<h<<endl;
    ans[u]=z+h+i*p[u].first+(n-i-1)*p[u].second;
    h+=p[u].second;

}
int x,y;
while(m--)
{
    cin>>x>>y;
    x--;
    y--;
    ll dd=min(p[x].first+p[y].second,p[x].second+p[y].first);
    ans[x]-=dd;
    ans[y]-=dd;
}
for(int i=0;i<n;i++)cout<<ans[i]<<" ";
   return 0;
}