#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l[100009],r[100009],c[100009],pr[300009][2];
vector<pair<int,int> > v[2];
vector<int>ed[100009];
bool vis[100009];
void cn(int x,int y)
{
    if(l[x]<=l[y] && r[x]>=l[y]){ed[x].push_back(y);ed[y].push_back(x);
    return ;}
    if(l[y]<=l[x] && r[y]>=l[x]){ed[x].push_back(y);ed[y].push_back(x);
    return ;}
    return ;
}
void pos(int x,int y)
{
    if(l[x]>l[y])swap(x,y);
    if(pr[l[x]][1-c[x]]>=l[y]){ed[x].push_back(y);ed[y].push_back(x);
    return ;}
    return ;
}
void go(int x)
{
    if(vis[x])return ;
    vis[x]=true;
    for(int i=0;i<ed[x].size();i++)go(ed[x][i]);
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
       for(int i=0;i<2*n+3;i++)pr[i][0]=pr[i][1]=0;
       vector<int>hs;
       for(int i=0;i<n;i++)
       {
           ed[i].clear();
           vis[i]=0;
           cin>>c[i]>>l[i]>>r[i];

            hs.push_back(l[i]);
            hs.push_back(r[i]);
       }
       v[0].clear();
       v[1].clear();
       vector<int>g;
       sort(hs.begin(),hs.end());
       g.push_back(hs[0]);
       for(int i=1;i<hs.size();i++)if(hs[i]>hs[i-1])g.push_back(hs[i]);
       for(int i=0;i<n;i++)
       {
           l[i]=upper_bound(g.begin(),g.end(),l[i])-g.begin();
           r[i]=upper_bound(g.begin(),g.end(),r[i])-g.begin();
           v[c[i]].push_back({l[i],i});
           pr[l[i]][c[i]]=max(pr[l[i]][c[i]],r[i]);
       }
       for(int i=1;i<=2*n+2;i++)
       {
           pr[i][0]=max(pr[i-1][0],pr[i][0]);
           pr[i][1]=max(pr[i-1][1],pr[i][1]);

       }
       sort(v[0].begin(),v[0].end());
       sort(v[1].begin(),v[1].end());
       for(int u=0;u<2;u++)
       for(int i=0;i<v[u].size();i++)
       {
           if(i+1<v[u].size())pos(v[u][i].second,v[u][i+1].second);
           int q=lower_bound(v[1-u].begin(),v[1-u].end(),make_pair(v[u][i].first,-1))-v[1-u].begin();
           if(q==v[1-u].size())continue;
           cn(v[u][i].second,v[1-u][q].second);
       }
       int ans=0;
       for(int i=0;i<n;i++)
       {
           if(vis[i])continue;
           ans++;
           go(i);
       }
       cout<<ans<<endl;


    }


    return 0;

}