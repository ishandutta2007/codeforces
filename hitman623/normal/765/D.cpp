#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
map < long ,vector <long> > a;
long long n,f[100005],i,h[100005]={0},g[100005],m=0;
long visi[100005]={0};
void dfs(long node)
{
    visi[node]=1;
    g[node]=m;
    long i;
    for(i=0;i<a[node].size();++i)
        if(visi[a[node][i]]==0)
        dfs(a[node][i]);
}
int main()
{
    cin>>n;
    for(i=1;i<=n;++i)
      cin>>f[i];
    for(i=1;i<=n;++i)
        {a[i].pb(f[i]);
        a[f[i]].pb(i);}
    for(i=1;i<=n;++i)
    if(visi[i]==0)   {m++;dfs(i);}
    for(i=1;i<=n;++i)
        {
            if(h[g[i]]!=f[i] && h[g[i]]!=0)
                { cout<<-1;exit(0); }
            h[g[i]]=f[i];
        }
    cout<<m<<endl;
    for(i=1;i<=n;++i)
        cout<<g[i]<<" ";
    cout<<endl;
    for(i=1;i<=m;++i)
        cout<<h[i]<<" ";
    return 0;
}