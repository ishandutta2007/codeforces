/***************************************************************
    File name: 3943.cpp
    Author: huhao
    Create time: Tue 25 Jun 2019 06:42:15 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
    int r=0,t=1,c=getchar();
    while(c<'0'||c>'9')
    {
        t=c=='-'?-1:1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        r=r*10+c-48;
        c=getchar();
    }
    return r*t;
}
const int N=100010,K=20,inf=1<<29;
int n,d[N],k,m,_n,a[N],b[N],c[N],f[(1<<K)+10],q[N],l,r,_d[K+10][K+10];
int count(int k)
{
    return k?1+count(k-(k&(-k))):0;
}
int main()
{
    n=read()+1;
    k=read();
    m=read();
    fr(i,1,k)
    {
        c[i]=read();
        if(i==1)
        {
            a[++_n]=c[i];
        }
        else if(c[i]-c[i-1]!=1)
        {
            a[++_n]=c[i-1]+1;
            a[++_n]=c[i];
        }
    }
    a[++_n]=c[k]+1;
    fr(i,1,m)
        b[i]=read();
    fr(i,1,_n)
    {
        fr(j,1,n)
            d[j]=inf;
        d[a[i]]=0;
        q[l=r=1]=a[i];
        while(l<=r)
        {
            int u=q[l];
            l++;
            fr(i,1,m)
            {
                if(u-b[i]>=1&&d[u-b[i]]==inf)
                {
                    d[u-b[i]]=d[u]+1;
                    q[++r]=u-b[i];
                }
                if(u+b[i]<=n&&d[u+b[i]]==inf)
                {
                    d[u+b[i]]=d[u]+1;
                    q[++r]=u+b[i];
                }
            }
        }
        fr(j,1,_n)
            _d[i][j]=d[a[j]];
    }
    fr(i,1,(1<<_n)-1)
        f[i]=inf;
    fr(i,1,(1<<_n)-1)
        if(count(i)%2==0)
        {
            fr(j,1,_n)
                if(i&(1<<(j-1)))
                    fr(k,j+1,_n)
                        if((i&(1<<(k-1)))&&_d[j][k]!=inf)
                            f[i]=min(f[i],f[i^(1<<(j-1))^(1<<(k-1))]+_d[j][k]);
        }
    printf("%d\n",f[(1<<_n)-1]>(1<<28)?-1:f[(1<<_n)-1]);
    return 0;
}