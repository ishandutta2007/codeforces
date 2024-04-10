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
#define hell 99991
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vll from[100005],to[100005];
long n,m,k,i,d,ar,de,co,start[1000006],en[1000006],ans=1e17,j,cur;
int main()
{
    io
    cin>>n>>m>>k;
    for(i=0;i<m;++i)
    {
        cin>>d>>de>>ar>>co;
        if(ar==0)
        from[de].pb({d,co});
        else to[ar].pb({d,co});
    }
    for(i=1;i<=n;++i)
    {
        if(from[i].size()==0 || to[i].size()==0) {cout<<-1;exit(0);}
        sort(from[i].begin(),from[i].end());
        sort(to[i].begin(),to[i].end());
        if(from[i].size()>1)
        for(j=1;j<from[i].size();++j)
        from[i][j].y=min(from[i][j].y,from[i][j-1].y);
        if(to[i].size()>1)
        for(j=to[i].size()-2;j>=0;--j)
        to[i][j].y=min(to[i][j].y,to[i][j+1].y);
        cur=1e12;
        for(j=0;j<from[i].size();++j)
        {
            long dd=from[i][j].x;
            while(j<from[i].size() && from[i][j].x==dd)
            j++;
            j--;
            start[dd]+=from[i][j].y-cur;
            cur=from[i][j].y;
        }
        cur=1e12;
        for(j=to[i].size()-1;j>=0;--j)
        {
            long dd=to[i][j].x;
            while(j>=0 && to[i][j].x==dd)
            j--;
            j++;
            en[dd]+=to[i][j].y-cur;
            cur=to[i][j].y;
        }
    }
    cur=1e12*n;
    for(i=0;i<1e6+2;++i)
    {
        cur+=start[i];
        start[i]=cur;
    }
    cur=1e12*n;
    for(i=1e6+1;i>=0;i--)
    {
        cur+=en[i];
        en[i]=cur;
    }
    for(i=0;i+k<1e6+1;++i)
    ans=min(ans,start[i]+en[i+k+1]);
    if(ans>1e12)
    cout<<-1;
    else
    cout<<ans;
    return 0;
}