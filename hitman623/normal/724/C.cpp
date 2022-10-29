#include <bits/stdc++.h>
#define long long long
#define pb push_back
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
long n,m,k,i,x[100005],y[100005],j,t=0,tim;
map < long , long > mp[2][2];
map < long , pll > tt;
void solve(long f,long x,long y,long d)
{
    long xx,yy;
    if(x==n && y==m) return ;
    if(f==0)
    {
        if(d==0)
        {
            if(mp[f][d].find(y-x)!=mp[f][d].end()) return;
            mp[f][d][y-x]=t;
            tt[t]={x,y};
            if(n-x<=m-y)
            {
                xx=n,yy=y+(n-x);
                t+=n-x;
                solve(1,xx,yy,0);
            }
            else
            {
                yy=m,xx=x+m-y;
                t+=m-y;
                solve(1,xx,yy,1);
            }
        }
        else
        {
            if(mp[f][d].find(y-x)!=mp[f][d].end()) return;
            mp[f][d][y-x]=t;
            tt[t]={x,y};
            if(x<=y)
            {
                xx=0,yy=y-x;
                t+=x;
                solve(1,xx,yy,1);
            }
            else
            {
                yy=0,xx=x-y;
                t+=y;
                solve(1,xx,yy,0);
            }
        }
    }
    else
    {
        if(d==0)
        {
            if(mp[f][d].find(y+x)!=mp[f][d].end()) return;
            mp[f][d][y+x]=t;
            tt[t]={x,y};
            if(x<=m-y)
            {
                xx=0,yy=y+x;
                t+=x;
                solve(0,xx,yy,0);
            }
            else
            {
                yy=m,xx=x-(m-y);
                t+=m-y;
                solve(0,xx,yy,1);
            }
        }
        else
        {
            if(mp[f][d].find(y+x)!=mp[f][d].end()) return;
            mp[f][d][y+x]=t;
            tt[t]={x,y};
            if(n-x<=y)
            {
                xx=n,yy=y-(n-x);
                t+=n-x;
                solve(0,xx,yy,1);
            }
            else
            {
                yy=0,xx=x+y;
                t+=y;
                solve(0,xx,yy,0);
            }
        }
    }
}
int main()
{
    io
    cin>>n>>m>>k;
    for(i=0;i<k;++i)
    cin>>x[i]>>y[i];
    solve(0,0,0,0);
    for(i=0;i<k;++i)
    {
        long ans=1e17;
        if(mp[0][0].find(y[i]-x[i])!=mp[0][0].end())
        {
            tim=mp[0][0][y[i]-x[i]];
            ans=min(ans,tim+(x[i]-tt[tim].x));
        }
        if(mp[0][1].find(y[i]-x[i])!=mp[0][1].end())
        {
            tim=mp[0][1][y[i]-x[i]];
            ans=min(ans,tim+(tt[tim].x-x[i]));
        }
        if(mp[1][0].find(y[i]+x[i])!=mp[1][0].end())
        {
            tim=mp[1][0][y[i]+x[i]];
            ans=min(ans,tim+(tt[tim].x-x[i]));
        }
        if(mp[1][1].find(y[i]+x[i])!=mp[1][1].end())
        {
            tim=mp[1][1][y[i]+x[i]];
            ans=min(ans,tim+(x[i]-tt[tim].x));
        }
        if(ans<1e17)
        cout<<ans<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}