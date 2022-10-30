#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e3+51;
ll length,width,ub,maxn,res;
ll row[MAXN],col[MAXN],rp[MAXN],cp[MAXN],rmin[MAXN],cmin[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline ll calc(ll num)
{
    ll res=0;
    while(num)
    {
        res+=(num%10),num/=10;
    }
    return res;
}
int main()
{
    length=read(),width=read();
    memset(rmin,0x3f,sizeof(rmin)),memset(cmin,0x3f,sizeof(cmin));
    for(register int i=1;i<=length;i++)
    {
        row[i]=read();
        rp[i]=rp[i-1]+row[i];
    }
    for(register int i=1;i<=width;i++)
    {
        col[i]=read();
        cp[i]=cp[i-1]+col[i];
    }
    ub=read();
    for(register int i=1;i<=length;i++)
    {
        for(register int j=i;j<=length;j++)
        {
            rmin[j-i+1]=min(rmin[j-i+1],rp[j]-rp[i-1]);
        }
    }
    for(register int i=1;i<=width;i++)
    {
        for(register int j=i;j<=width;j++)
        {
            cmin[j-i+1]=min(cmin[j-i+1],cp[j]-cp[i-1]);
        }
    }
    for(register int i=1;i<=length;i++)
    {
        for(register int j=1;j<=width;j++)
        {
            if(rmin[i]*cmin[j]<=ub)
            {
                maxn=max(maxn,(ll)(i*j));
            }
        }
    }
    printf("%I64d",maxn);
}