#include <bits/stdc++.h>
#define pb push_back
using namespace std;

map <long ,vector <long> > a;
long n,m,k,g[100000],i,ans=0,b=0,le,visi[100000]={0},x,y,ma=0;
void dfs(long node,long p)
{
    long i;
    if(visi[node]==1) return;
    else if(a[node].size()==1 && node!=p) {ans++;return;}
    else
    {
        visi[node]=1;
        ans++;
    for(i=0;i<a[node].size();++i)
    {
      dfs(a[node][i],p);
    }
    }
}
int main()
{
    cin>>n>>k>>m;
    for(i=0;i<m;++i)
        cin>>g[i];
    for(i=0;i<k;++i)
    {
      cin>>x>>y;
      a[x].pb(y);
      a[y].pb(x);
    }
    le=n;
    for(i=0;i<m;++i)
    {   ans=0;
        dfs(g[i],g[i]);
        b+=(ans*(ans-1))/2;
        le-=ans;
        ma=max(ans,ma);
    }
    b+=((ma+le)*(ma+le-1))/2-(ma*(ma-1))/2;
    b-=k;
    cout<<b;
    return 0;
}