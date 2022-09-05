#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
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

template <typename T> void chmin(T &x,const T &y)
{
    if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
    if(x<y)x=y;
}

struct vec
{
    int *a,n;
    void pb(int x)
    {
        if(n==(n&-n))
        {
            int *_a=new int [n*2];
            memcpy(_a,a,n*sizeof(int));
            a=_a;
        }
        a[n++]=x;
    }
};

const int N=10,U=1<<N;
int lk[N][N];
ll f[U];

int q[N];
ll qa[N][N],*a[N];
ll gauss(int m)
{
    ll ans=1;
    for(int i=0;i<m;++i)
    {
        for(int j=i+1;j<m;++j)
        {
            while(a[j][i])
            {
                ll bi=a[i][i]/a[j][i];
                for(int k=i;k<m;++k)
                 a[i][k]-=a[j][k]*bi;

                swap(a[i],a[j]);
                ans=-ans;
            }
        }
        ans*=a[i][i];
    }
    return ans;
}

int main()
{
    //freopen("1.in","r",stdin);//freopen("1.out","w",stdout);

    for(int i=0;i<N;++i)a[i]=qa[i];

    int n=read(),m=read(),k=read();
    while(m--)
    {
        int x=read()-1,y=read()-1;
        ++lk[x][y];++lk[y][x];
    }
    int u=(1<<n)-1;
    for(int s=1;s<u;++s)
    {
        ll ans=1;

        m=0;
        for(int i=0;i<n;++i)
        if(!(s&(1<<i))) q[m++]=i;
        for(int i=0;i<n;++i)
        if(s&(1<<i)) 
        {
            int cnt=0;
            for(int j=0;j<m;++j) cnt+=lk[i][q[j]];
            ans*=cnt;
        }
        if(n-m<k||ans==0)continue;

        for(int i=0;i<m;++i)
        for(int j=0;j<m;++j)
         a[i][j]=0;

        for(int i=0;i<m;++i)
        for(int j=0;j<i;++j)
        {
          int w=lk[q[i]][q[j]];
          a[i][i]+=w;
          a[j][j]+=w;
          a[i][j]=a[j][i]=-w;
        }

        ans*=gauss(m-1);

        if((n-m-k)%2==1) f[s]=-ans;
        else f[s]=ans;
    }

    for(int i=0;i<n;++i)
    for(int s=0;s<u;++s)
    if( (s&(1<<i))==0 ) f[s]+=f[s+(1<<i)];

    ll ans=0;
    for(int s=0;s<u;++s)
    {
        int cnt=0;
        for(int i=0;i<n;++i)
        if(s&(1<<i))++cnt;
        if(cnt==k)ans+=f[s];
    }
    cout<<ans;
}