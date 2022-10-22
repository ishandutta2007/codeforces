//            
#define setI(x) freopen(x,"r",stdin)
#define setO(x) freopen(x,"w",stdout)
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
// #define N 
using namespace std;
inline char gc(){static char buf[1<<21],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,r;
int b[65];
int pw[1005];
struct matrix
{
    int n,m;
    int a[105][105];
    matrix()
    {
        memset(a,0,sizeof(a));
        n=m=0;
    }
}f[65];
inline matrix operator * (matrix &x,matrix &y)
{
    matrix res;
    res.n=x.n;
    res.m=y.m;
    for (int i=0;i<x.n;i++)
        for (int j=0;j<y.m;j++)
            for (int k=0;k<y.n;k++)
            {
                int nn=(res.a[i][j]+x.a[i][k]*y.a[k][j]%mod);
                res.a[i][j]=(nn>=mod)?nn-mod:nn;
            }
    return res;
}
inline matrix operator >> (matrix &x,int p)
{
    matrix res;
    res.n=x.n,res.m=x.m;
    for (int i=0;i<x.n-1;i++)
        for (int j=0;j<x.m-1;j++)
            res.a[(i+p)%m][(j+p)%m]=x.a[i][j];
    for (int i=0;i<x.m-1;i++)
        res.a[x.n-1][(i+p)%m]=x.a[x.n-1][i];
    res.a[x.n-1][x.m-1]=1;
    return res;
}
namespace BF
{
    int tn[105];
    int nowans=0;
    int c[65];
    void main()
    {
        nowans=2;
        for (int i=0;i<r;i++) c[i]=0;
        int nowx=0;
        tn[0]=1;
        for (int i=1;i<n;i++)
        {
            int l=0;
            while (c[l]==m-1)
            {
                nowx=(nowx-c[l]*b[l]%m+m)%m;
                c[l]=0;
                l++;
            }
            c[l]++;
            nowx=(nowx+b[l])%m;
            int p=nowans;
            if (tn[nowx]) nowans=(nowans-tn[nowx]+mod)%mod;
            tn[nowx]=p;
            nowans=(nowans+p)%mod;
        }
        writeln(nowans);
    }
}
void BellaKira()
{
    n=read(),m=read();
    pw[0]=1;
    for (int i=1;i;i++)
    {
        // cout<<i<<" "<<pw[i-1]<<endl;
        if (n/pw[i-1]<m)
        {
            r=i;
            break;
        }
        pw[i]=pw[i-1]*m;
        // cout<<i<<" "<<pw[i]<<endl;
    }
    // cout<<"?"<<r<<endl;
    for (int i=0;i<r;i++)
        b[i]=1;
    f[0].n=m+1,f[0].m=m+1;
    for (int i=0;i<m;i++)
    {
        f[0].a[i][0]=1;
        f[0].a[i][i]=1;
    }
    f[0].a[m][0]=1;
    f[0].a[m][m]=1;
    
    for (int now=1;now<r;now++)
    {
        int x=0;
        f[now]=f[now-1];
        for (int i=1;i<m;i++)
        {
            int p=b[now-1]*i%m;
            matrix nowmt=f[now-1]>>p;
            f[now]=f[now]*nowmt;
        }
    }
    matrix ans;
    matrix ans1;
    ans.n=1;
    ans.m=m+1;
    ans.a[0][m]=1;

    ans1.n=m+1,ans1.m=m+1;
    for (int i=0;i<ans1.n;i++)
        ans1.a[i][i]=1;

    int sm=0;
    for (int i=r-1;i>=0;i--)
    {
        int p=0;
        for (int j=0;j<n/pw[i];j++)
        {
            matrix nowmt=(f[i]>>(sm));
            ans1=ans1*nowmt;
            sm+=b[i]%m;
            sm%=m;
        }
        n%=pw[i];
    }
    ans=ans*ans1;
    int nowans=0;
    for (int i=0;i<ans.m-1;i++)
        nowans=(nowans+ans.a[0][i])%mod;
    writeln((nowans+1)%mod);
}
signed main()
{
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*
*/