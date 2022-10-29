#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector < long long > a[1000006];
long long visi[1000006]={0},sl[1000006]={0};

void dfs(long long node)
{
    long long i;
    visi[node]=1;
    for(i=0;i<a[node].size();++i)
        if(!visi[a[node][i]])
        dfs(a[node][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,u,v,i,l=0,ans=0,s,f=0;
    cin>>n>>m;
    for(i=0;i<m;++i)
    {
        cin>>u>>v;
        if(u==v) {sl[u]++;l++;continue;}
        a[u].pb(v);
        a[v].pb(u);
    }
    for(i=1;i<=n;++i)
    if(a[i].size()==0 && sl[i]==0) visi[i]=1;
    for(i=1;i<=n;++i)
    {
        if(f==1 && visi[i]==0) {cout<<0;exit(0);}
        if(visi[i]==0) {dfs(i);f=1;}
    }
    for(i=1;i<=n;++i)
    {
        s=a[i].size();
        ans+=(s*(s-1))/2;
    }
    ans+=l*(m-1)-(l*(l-1))/2;
    cout<<ans;
    return 0;
}