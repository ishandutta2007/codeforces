#include <bits/stdc++.h>
#define pb push_back
#define long int
#define pll pair < long , long >
#define vl vector < long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vl a[200005];
long ans[200005]={0},val[200005];
set < long > s;
set < long > :: iterator it;
void dfs(long node,long par)
{
    long i;
    set < long > ss;
    for(it=s.begin();it!=s.end();it++)
    ss.insert(__gcd(*it,val[node]));
    it=s.begin();
    if(node!=1 && *s.begin()==0) it++;
    ss.insert(*it);
    swap(s,ss);
    it=s.end();
    it--;
    ans[node]=*it;
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    dfs(a[node][i],node);
    swap(s,ss);
}
int main()
{
    io
    long n,i,x,y;
    cin>>n;
    for(i=1;i<=n;++i)
    cin>>val[i];
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    s.insert(0);
    dfs(1,-1);
    for(i=1;i<=n;++i)
    cout<<ans[i]<<" ";
    return 0;
}