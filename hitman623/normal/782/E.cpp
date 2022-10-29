#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector <long> a[200005],path[200005];
long visi[200005]={0},l=1,c;
void dfs(long node)
{
    long i,k;
    visi[node]=1;
    for(i=0;i<a[node].size();++i)
    {
        if(!visi[a[node][i]])
        {
            if(path[l].size()>=c) l++;
            path[l].pb(a[node][i]);
            dfs(a[node][i]);
            if(path[l].size()<c)
            path[l].pb(node);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   long n,m,k,x,y,i,j;
   cin>>n>>m>>k;
   for(i=0;i<m;++i)
   {
       cin>>x>>y;
       a[x].pb(y);
       a[y].pb(x);
   }
   c=(2*n)/k+!!((2*n)%k);
   path[1].pb(1);
   dfs(1);
   for(i=1;i<=k;++i)
   {
       if(path[i].size()==0) path[i].pb(1);
       cout<<path[i].size()<<" ";
       for(j=0;j<path[i].size();j++)
       cout<<path[i][j]<<" ";
       cout<<endl;
   }
   return 0;
}