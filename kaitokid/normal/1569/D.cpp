#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lx[200009],ly[200009],x[300009],y[300009],id[300009];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
int n,m,k;
cin>>n>>m>>k;
for(int i=0;i<n;i++)cin>>lx[i];
for(int i=0;i<m;i++)cin>>ly[i];
for(int i=0;i<k;i++)cin>>x[i]>>y[i];
vector<int>p;
for(int i=0;i<k;i++)p.push_back(x[i]);
sort(p.begin(),p.end());
ll ans=0;
for(int i=0;i+1<n;i++)
{
    ll g=lower_bound(p.begin(),p.end(),lx[i+1])-upper_bound(p.begin(),p.end(),lx[i]);
    ans+=g*(g-1)/2;
}
p.clear();
for(int i=0;i<k;i++)p.push_back(y[i]);
sort(p.begin(),p.end());
for(int i=0;i+1<m;i++)
{
    ll g=lower_bound(p.begin(),p.end(),ly[i+1])-upper_bound(p.begin(),p.end(),ly[i]);
    ans+=g*(g-1)/2;
}
map<pair<int,int> ,ll >mp[2];
for(int i=0;i<k;i++)
{
int u=lower_bound(lx,lx+n,x[i])-lx;
int v=lower_bound(ly,ly+m,y[i])-ly;
int dd=0,ff=0;
if((u<n && lx[u]==x[i]))dd=1;
    if(v<m && ly[v]==y[i])ff=1;
if(dd && ff)continue;
if(dd)ans-=(mp[0][{u,v}]++);
else ans-=(mp[1][{u,v}]++);
//cout<<i<<" "<<u<<" "<<v<<endl;
}
cout<<ans<<endl;
}

    return 0;
}