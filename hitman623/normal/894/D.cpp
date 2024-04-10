#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
vll a[1000006];
vl v[1000006],pp[1000006];
long x[1000006],cur=0,p[1000006],w[1000006],ww;
void dfs(long node,long par,long l,long ww)
{
    long i,j;
    p[node]=par;
    w[node]=ww;
    x[node]=l;
    v[node].pb(l);
    for(i=0;i<a[node].size();++i)
    if(a[node][i].x!=par)
    {
        dfs(a[node][i].x,node,l+a[node][i].y,a[node][i].y);
        for(j=0;j<v[a[node][i].x].size();++j)
        v[node].pb(v[a[node][i].x][j]);
    }
    sort(v[node].begin(),v[node].end());
    pp[node].resize(v[node].size());
    pp[node][0]=v[node][0];
    for(i=1;i<v[node].size();++i)
    pp[node][i]=v[node][i]+pp[node][i-1];
}
int main()
{
    io
    long n,m,i,xx,y,d,h;
    cin>>n>>m;
    for(i=1;i<=n-1;++i)
    {
        cin>>ww;
        xx=i+1;
        y=(i+1)/2;
        a[y].pb({xx,ww});
    }
    dfs(1,-1,0,0);
    for(i=0;i<m;++i)
    {
        long ans=0;
        cin>>d>>h;
        long t=upper_bound(v[d].begin(),v[d].end(),h+x[d])-v[d].begin();
        if(t)
        ans=(h+x[d])*t-pp[d][t-1];
        while(p[d]!=-1)
        {
            long w1=w[d];
            if(h>w1) ans+=h-w1;
            if(a[p[d]].size()>1)
            {
                if(a[p[d]][0].x==d)
                {
                    long tm=h-(a[p[d]][1].y+w1)+x[a[p[d]][1].x];
                    long tt=upper_bound(v[a[p[d]][1].x].begin(),v[a[p[d]][1].x].end(),tm)-v[a[p[d]][1].x].begin();
                    if(tt!=0)
                    ans+=tt*tm-pp[a[p[d]][1].x][tt-1];
                }
                else
                {
                    long tm=h-(a[p[d]][0].y+w1)+x[a[p[d]][0].x];
                    long tt=upper_bound(v[a[p[d]][0].x].begin(),v[a[p[d]][0].x].end(),tm)-v[a[p[d]][0].x].begin();
                    if(tt!=0)
                    ans+=tt*tm-pp[a[p[d]][0].x][tt-1];
                }
            }
            h-=w[d];
            d=p[d];
        }
        cout<<ans<<"\n";
    }

    return 0;
}