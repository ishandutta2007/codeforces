#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll pr[200009];
vector<ll>ed[200009];
bool us[200009];
vector<pair<ll,pair<ll,ll> > >g;
set<ll>st;
void go(int x,int p)
{
    pr[x]=p;
    set<ll>::iterator it=st.begin();
    ll u=0;
    while(it!=st.end())
    {
    ll r=(*it);
    while(ed[x][u]<r)u++;
    if(ed[x][u]==r){it++;continue;}
    st.erase(it);
    go(r,p);
    it=upper_bound(st.begin(),st.end(),r);
    }

}
ll p(ll x)
{
    if(pr[x]==x)return x;
    return pr[x]=p(pr[x]);
}
int main()
{ios::sync_with_stdio(0);
cin>>n>>m;
ll qq=0;
for(int i=0;i<m;i++)
{
    ll x,y,z;
    cin>>x>>y>>z;
    qq^=z;
    ed[x].push_back(y);
    ed[y].push_back(x);
    g.push_back(make_pair(z,make_pair(x,y)));
}
for(int i=1;i<=n;i++)
    {pr[i]=i;st.insert(i);
    sort(ed[i].begin(),ed[i].end());
    ed[i].push_back(n+5);
    }
    if(m==0){cout<<0;return 0;}
 ll r=0;
for(int i=1;i<=n;i++)
{

    if(pr[i]==i)
        {st.erase(i);go(i,i);r++;}


}
sort(g.begin(),g.end());
ll hh=n*(n-1)/2;
hh-=m;
if(r==1 && hh> n-1){cout<<0;return 0;}
if(r==1){cout<<min(qq,g[0].first);return 0;}
ll ans1=0;
for(int i=0;i<m;i++)
{
    if(r==1)break;
    ll u=g[i].second.first;
    ll v=g[i].second.second;
    ll w=g[i].first;
    if(p(u)!=p(v)){ans1+=w;us[i]=true;pr[p(u)]=p(v);r--;}
    if(r==1)break;

}
ll ans2=ans1;
ans1+=qq;
for(int i=1;i<=n;i++)pr[i]=i;

ll ss=1000000000000;
for(int i=0;i<m;i++)
{
    int u=g[i].second.first;
    int v=g[i].second.second;
    ll w=g[i].first;
    if(p(u)!=p(v)){pr[p(u)]=p(v);
    if(!us[i]){ss=w;break;}
    }


}
for(int i=1;i<=n;i++)pr[i]=i;
int fd=n;
for(int i=0;i<m;i++)
{
    if(!us[i])continue;
    int u=g[i].second.first;
    int v=g[i].second.second;
    ll w=g[i].first;
    if(p(u)!=p(v)){pr[p(u)]=p(v);fd--;}


}
if(hh>fd-1)ss=0;
ans2+=ss;
cout<<min(ans1,ans2);
    return 0;
}