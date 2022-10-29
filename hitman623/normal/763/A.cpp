#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define bs binary_search
#define all(a) a.begin(),a.end()
using namespace std;
ll color[100005],cnt,node,visi[100005]={0},col,f=1;
vector< long > sr;
map <long, vector < long > >  a;
map <long,long> c;
void dfs(long n,long t)
{
    visi[n]=f;
    long i;
    for(i=0;i<a[n].size();i++)
    {
        if(f==t) break;
        if(visi[a[n][i]]==f) continue;
        if(n==node) col=color[a[n][i]];
        if(color[a[n][i]]!=col) {f=t;break;}
        dfs(a[n][i],t);
    }
}
int main()
{
    ll n,x,y,i,j;
    cin>>n;
    for(i=0;i<n-1;++i)
        {cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);}
    for(i=1;i<=n;++i)
    {
        cin>>color[i];
        c[color[i]]=1;
    }
    cnt=c.size();
    node=-1;
    for(i=1;i<=n;++i)
    {
        c.clear();
        c[color[i]]=1;
        for(j=0;j<a[i].size();++j)
            c[color[a[i][j]]]=1;
            if(c.size()==cnt)sr.pb(i);
    }
    if(sr.size()>3 && cnt>2) {cout<<"NO";exit(0);}
    for(i=0;i<sr.size();++i)
    {
        f=1;node=sr[i];dfs(sr[i],0);
        if(f) {cout<<"YES"<<endl<<sr[i];exit(0);}
        else dfs(sr[i],1);
    }
    cout<<"NO";
    return 0;
}