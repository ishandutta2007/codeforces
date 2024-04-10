#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector < long > a[300005],v;
set < long > adj[300005];
set < long > ::iterator q,w;
vector < long > ::iterator jt;
map < vector < long > , vector < long > > mp;
map < vector < long > , vector < long > > ::iterator it;
long n,m,i,j,x,y,col[300005]={0},c=0,visi[300005]={0},num[300005];
void dfs(long node , long c)
{
    visi[node]=1;
    long i;
    if(adj[node].size()>2) {cout<<"NO";exit(0);}
    col[node]=c;
    if(adj[node].size()==0) return ;
    else if(adj[node].size()==1)
    {
        q=adj[node].begin();
        if(!visi[*q])
        dfs(*q,c+1);
    }
    else
    {
        q=adj[node].begin();
        w=q;
        w++;
        if(visi[*q] && visi[*w]) {cout<<"NO";exit(0);}
        if(!visi[*q])
        dfs(*q,c+1);
        if(!visi[*w])
        dfs(*w,c+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;++i)
    a[i].pb(i);
    for(i=0;i<m;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for(i=1;i<=n;++i)
    {
        sort(a[i].begin(),a[i].end());
        mp[a[i]].pb(i);
    }
    for(it=mp.begin();it!=mp.end();it++)
    {
        c++;
        for(jt=it->second.begin();jt!=it->second.end();jt++)
        num[*jt]=c;
    }
    for(it=mp.begin();it!=mp.end();it++)
    {
        v=it->first;
        for(i=0;i<v.size();++i)
        {
            if(!binary_search(it->second.begin(),it->second.end(),v[i]))
            adj[num[*it->second.begin()]].insert(num[v[i]]);
        }
    }
    for(i=1;i<=c;++i)
    if(adj[i].size()<=1) break;
    if(i==c+1) {cout<<"NO";exit(0);}
    dfs(i,1);
    cout<<"YES"<<endl;
    for(i=1;i<=n;++i)
    cout<<col[num[i]]<<" ";
    return 0;
}