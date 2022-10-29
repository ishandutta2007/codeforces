#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define vl vector < int >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vl v[100005],ans,a[100005];
int n,m,i,l,k=1e5,x,val[100005],visi[200005]={0},j;
set < int > s;
void dfs(long node)
{
    long i;
    visi[node]=1;
    s.insert(node);
    for(i=0;i<a[node].size();++i)
    if(!visi[a[node][i]])
    dfs(a[node][i]);
    else if(s.find(a[node][i])!=s.end()) {cout<<"No";exit(0);}
    for(i=0;i<a[node].size();++i)
    while(val[node]>val[a[node][i]])
    {
        ans.pb(node);
        val[node]-=m;
    }
    s.erase(node);
}
int main()
{
    io
    cin>>n>>m;
    for(i=1;i<=m;++i)
    val[i]=m+i;
    for(i=0;i<n;++i)
    {
        cin>>l;
        while(l--)
        {
            cin>>x;
            v[i].pb(x);
        }
    }
    for(i=0;i<n-1;++i)
    {
        for(j=0;j<min(v[i].size(),v[i+1].size());++j)
        if(val[v[i][j]]!=val[v[i+1][j]]) {a[v[i][j]].pb(v[i+1][j]);break;}
        if(j==min(v[i].size(),v[i+1].size()) && v[i].size()>v[i+1].size()) {cout<<"No";return 0;}
    }
    for(i=1;i<=m;++i)
    dfs(i);
    for(i=1;i<=m;++i)
    if(val[i]<=0) {cout<<"No";return 0;}
    cout<<"Yes\n";
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();++i)
    cout<<ans[i]<<" ";
    return 0;
}