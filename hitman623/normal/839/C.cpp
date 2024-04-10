#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vl a[100005];
double ans=0;
void dfs(long node,long par,double p,double l)
{
    if(a[node].size()==1 && a[node][0]==par) ans+=p*l;
    long i;
    double m=a[node].size()-(node!=1);
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    dfs(a[node][i],node,p/m,l+1);
}
int main()
{
    io
    cout<<fixed<<setprecision(10);
    long n,x,y,i;
    cin>>n;
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,-1,1,0);
    cout<<ans;
    return 0;
}