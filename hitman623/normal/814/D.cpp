#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
struct s
{
    long x,y,r;
};
vl a[1002];
long visi[1003]={0},val[1003],ans=0;
long cmp(s a, s b)
{
    return a.r<b.r;
}
void dfs(long node,long f)
{
    long i;
    visi[node]=1;
    for(i=0;i<a[node].size();++i)
    if(!visi[a[node][i]])
    {
        ans+=f*val[a[node][i]];
        dfs(a[node][i],-f);
    }
}
int main()
{
    io
    vector < s > v;
    long n,i,j,xx,yy,rr;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>xx>>yy>>rr;
        v.pb({xx,yy,rr});
    }
    sort(v.begin(),v.end(),cmp);
    for(i=0;i<n;++i)
    val[i+1]=v[i].r*v[i].r;
    for(i=0;i<n;++i)
    for(j=i+1;j<n;++j)
    {
        if((v[j].x-v[i].x)*(v[j].x-v[i].x)+(v[j].y-v[i].y)*(v[j].y-v[i].y)<=v[j].r*v[j].r)
        {
            a[j+1].pb(i+1);
            break;
        }
    }
    for(i=n;i>=1;--i)
    if(!visi[i])
    {
        ans+=val[i];
        visi[i]=1;
        for(j=0;j<a[i].size();++j)
        {
            ans+=val[a[i][j]];
            dfs(a[i][j],-1);
        }
    }
    cout<<fixed;
    cout<<setprecision(10);
    double pi=3.14159265358979,d=ans*pi;
    cout<<d;
    return 0;
}