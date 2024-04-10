#include<bits/stdc++.h>
using namespace std;
 
template <typename T> void chmin(T&x,const T &y)
{
    if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
    if(x<y)x=y;
}
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define gc (c=getchar())
int read()
{
    char c;
    while(gc<'-');
    if(c=='-')
    {
        int x=gc-'0';
        while(gc>='0')x=x*10+c-'0';
        return -x;
    }
    int x=c-'0';
    while(gc>='0')x=x*10+c-'0';
    return x;
}
#undef gc
 
const int N=33,X=16;
int n,a[N][N];
int v[X][X][2][2],sv[2][X][1<<X],ans[1<<X];
     
int V(int x,bool d)
{
    return d?-x:x;
}
int check_xx(bool xx)
{
    int x=n/2;
    rep(i,0,x-1)
    rep(j,0,x-1)
    rep(bi,0,1)
    rep(bj,0,1)
        v[i][j][bi][bj]=abs(a[i][j]+V(a[i][j+x+1],bi)+V(a[i+x+1][j],bj)+V(a[i+x+1][j+x+1],bi^bj^xx));
    rep(bj,0,1)
    rep(j,0,x-1)
        sv[bj][j][0]=V(a[x][j],bj)+V(a[x][x+1+j],bj^xx);
    ans[0]=0;
    rep(i,0,x-1)
    {
        int u=1<<i;
        int v0=V(a[i][x],0)+V(a[x+1+i][x],xx),v1=V(a[i][x],1)+V(a[x+1+i][x],1^xx);
        int *a1=ans+u;
        rep(s,0,u-1)
        {
            a1[s]=ans[s]+v1;
            ans[s]+=v0;
        }
        rep(bj,0,1)
        rep(j,0,x-1)
        {
            int v0=v[i][j][0][bj],v1=v[i][j][1][bj];
            int *a0=sv[bj][j],*a1=a0+u;
            rep(s,0,u-1)
            {
                a1[s]=a0[s]+v1;
                a0[s]+=v0;
            }
        }
    }
    int u=1<<x;
    rep(j,0,x-1)
    {
        int *a0=sv[0][j],*a1=sv[1][j];
        rep(i,0,u-1)ans[i]+=max(a0[i],a1[i]);
    }
    int mx=0;
    rep(i,0,u-1)
    if(ans[i]>mx)mx=ans[i];
    return mx+V(a[x][x],xx);
}
 
int main()
{
#ifdef kcz
    freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
    n=read();
    rep(i,0,n-1)
    rep(j,0,n-1)a[i][j]=read();
    cout<<max(check_xx(0),check_xx(1));
}