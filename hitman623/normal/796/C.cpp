#include <bits/stdc++.h>
#define pb push_back

using namespace std;
vector < long long > a[300005];
long long visi[300005]={0};
long long n,s[300005],i,x,y,p,m=-1e9,ans=-1e9,f=0,g=0,h;
void dfs1(long node,long parent)
{
    long i;
    visi[node]=1;
    for(i=0;i<a[node].size();i++)
    {
        if(!visi[a[node][i]])
        {
            if(parent!=0 && s[parent]==m && s[a[node][i]]==m)
            {
                h=node;
                break;
            }
            dfs1(a[node][i],node);
        }
    }
}
void dfs(long long node)
{
    long long i,j;
    visi[node]=1;
    for(i=0;i<a[node].size();i++)
    {
        if(!visi[a[node][i]])
        {
            s[a[node][i]]++;
        for(j=0;j<a[a[node][i]].size();++j)
        {
            if(a[a[node][i]][j]!=node && !visi[a[a[node][i]][j]])
                s[a[a[node][i]][j]]++;
        }
            dfs(a[node][i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long i;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>s[i];
        if(m<=s[i]) {m=s[i];p=i;}
    }

    for(i=0;i<n-1;++i)
    {cin>>x>>y;
    a[x].pb(y);
    a[y].pb(x);}
    h=p;
    dfs1(p,0);
    memset(visi,0,sizeof(visi));
    dfs(h);
    for(i=1;i<=n;++i)
    ans=max(ans,s[i]);
    cout<<ans;
    return 0;
}