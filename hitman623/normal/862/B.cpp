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
long cnt[2]={0};
void dfs(long node,long par,long c)
{
    long i;
    cnt[c]++;
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    dfs(a[node][i],node,!c);
}
int main()
{
    io
    long n,i,x,y;
    cin>>n;
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,-1,0);
    cout<<cnt[0]*cnt[1]-n+1;
    return 0;
}