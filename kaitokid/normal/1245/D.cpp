#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod =1e9+7;
//priority_queue <pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> >;greater<pair<ll,pair<ll,ll> > >pr;
vector<pair<ll,pair<ll,ll> > >pr;
vector<pair<ll,ll> >v;

ll n ,x[2005],y[2005],c[2005],k[2003],par[2003];
ll pa(int z)
{
    if(par[z]==z)return z;
    par[z]=pa(par[z]);
    return par[z];
}
int main()
{
    ios::sync_with_stdio(0);

cin>>n;
for(int i=0;i<n;i++)par[i]=i;
for(int i=0;i<n;i++)cin>>x[i]>>y[i];
for(int i=0;i<n;i++)cin>>c[i];
for(int i=0;i<n;i++)cin>>k[i];
for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
{
 ll g=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);

    pr.push_back(make_pair(g,make_pair(i,j)));
}
sort(pr.begin(),pr.end());

ll rr=pr.size(),ans=0,q=0;
for(int i=0;i<rr;i++)
{

   ll a=pr[i].second.first;
     ll b=pr[i].second.second;
    if(pa(a)==pa(b))continue;
    if(max(c[pa(a)],c[pa(b)])<pr[i].first)continue;
    ans+=pr[i].first;
    v.push_back(make_pair(a,b));
    if(c[pa(a)]<c[pa(b)])par[pa(b)]=pa(a);
    else par[pa(a)]=pa(b);
}
for(int i=0;i<n;i++)if(pa(i)==i){ans+=c[i];q++;}
cout<<ans<<endl<<q<<endl;
for(int i=0;i<n;i++)if(pa(i)==i){cout<<i+1<<" ";}
cout<<endl<<v.size()<<endl;
for(int i=0;i<v.size();i++)cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
    return 0;
}