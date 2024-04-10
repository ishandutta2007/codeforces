#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector < long long > a[200005];
long long visi[200005]={0},c;

void dfs(long long node)
{
    visi[node]=1;
    c++;
    long long i;
    for(i=0;i<a[node].size();++i)
        if(!visi[a[node][i]])
        dfs(a[node][i]);
}
int main()
{
    long long n,m,x,y,i,s=0;
    cin>>n>>m;
    for(i=0;i<m;++i)
    {cin>>x>>y;
    a[x].pb(y);
    a[y].pb(x);}
    for(i=1;i<=n;++i)
    {
        if(!visi[i])
        {
            c=0;
            dfs(i);
            s+=c*(c-1)/2;
        }
    }
    if(s!=m) cout<<"NO";
    else cout<<"YES";
    return 0;
}