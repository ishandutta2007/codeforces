#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long k,n,q,x,y,i,j,val[200005];
int main()
{
    io
    long n,m,a[102][102],i,j,r[102]={0},c[102]={0},f=1,cnt=0,ans=1e9,val=-1;
    cin>>n>>m;
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
    cin>>a[i][j];
    for(i=0;i<=500;++i)
    {
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        r[0]=i;
        f=1;
        for(j=0;j<m;++j)
        c[j]=a[0][j]-r[0];
        for(j=1;j<n;++j)
        r[j]=a[j][0]-c[0];
        for(j=0;j<n;++j)
        if(r[j]<0) {f=-1;break;}
        for(j=0;j<m;++j)
        if(c[j]<0) {f=-1;break;}
        if(f==-1) continue;
        for(j=0;j<n;++j)
        {
            for(k=0;k<m;++k)
            if(a[j][k]!=r[j]+c[k]) {f=0;break;}
            if(f==0) break;
        }
        if(f)
        {
            cnt=0;
            for(j=0;j<n;++j)
            cnt+=r[j];
            for(j=0;j<m;++j)
            cnt+=c[j];
            if(cnt<ans) {ans=cnt,val=i;}
        }
    }
    if(val==-1) {cout<<-1;exit(0);}
    r[0]=val;
    f=1;
    for(j=0;j<m;++j)
    c[j]=a[0][j]-r[0];
    for(j=1;j<n;++j)
    r[j]=a[j][0]-c[0];
    cout<<ans<<endl;
    for(i=0;i<n;++i)
    while(r[i])
    {
        cout<<"row "<<i+1<<endl;
        r[i]--;
    }
    for(i=0;i<m;++i)
    while(c[i])
    {
        cout<<"col "<<i+1<<endl;
        c[i]--;
    }
    return 0;
}