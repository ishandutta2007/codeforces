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
long n,m,k,q,x[1000006],y[1000006],t[1000006],i,j;
long check(long mid)
{
    long i,j,ma[505][505]={0},p[505][505]={0};
    for(i=0;i<q;++i)
    {
        if(t[i]<=mid)
        ma[x[i]][y[i]]=1;
    }
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+ma[i][j];
    for(i=1;i<=n-k+1;++i)
    for(j=1;j<=m-k+1;++j)
    if(p[i+k-1][j+k-1]-p[i-1][j+k-1]-p[i+k-1][j-1]+p[i-1][j-1]==k*k)
    return 1;
    return 0;
}
int main()
{
    cin>>n>>m>>k>>q;
    for(i=0;i<q;++i)
    cin>>x[i]>>y[i]>>t[i];
    long lo=0,hi=1e9,mid;
    while(hi-lo>1)
    {
        mid=(lo+hi)/2;
        if(check(mid))
        hi=mid;
        else lo=mid;
    }
    if(check(lo)) cout<<lo;
    else if(check(mid)) cout<<mid;
    else if(check(hi)) cout<<hi;
    else cout<<-1;
    return 0;
}