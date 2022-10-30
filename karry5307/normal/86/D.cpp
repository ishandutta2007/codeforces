#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=4e5+51;
struct Query{
    ll l,r,ord;
};
Query q[MAXN];
ll cnt,qcnt,k,block,ql,qr,l=1,r=0;
long long int res;
ll color[MAXN],sum[MAXN<<2];
long long int result[MAXN];
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
inline bool cmp(Query x,Query y)
{
    return (x.r/block)==(y.r/block)?x.l<y.l:x.r<y.r;
}
inline void add(ll cur)
{
    res-=1ll*sum[color[cur]]*sum[color[cur]]*color[cur];
    sum[color[cur]]++;
    res+=1ll*sum[color[cur]]*sum[color[cur]]*color[cur];
}
inline void del(ll cur)
{
    res-=1ll*sum[color[cur]]*sum[color[cur]]*color[cur];
    sum[color[cur]]--;
    res+=1ll*sum[color[cur]]*sum[color[cur]]*color[cur];
}
int main()
{
    cnt=read(),qcnt=read(),block=sqrt(cnt);
    for(register int i=1;i<=cnt;i++)
    {
        color[i]=read();
    }
    for(register int i=0;i<qcnt;i++)
    {
        q[i].l=read(),q[i].r=read(),q[i].ord=i; 
    }
    sort(q,q+qcnt,cmp);
    for(register int i=0;i<qcnt;i++)
    {
        ql=q[i].l,qr=q[i].r;
        while(l<ql)
        {
            del(l++);
        }
        while(l>ql)
        {
            add(--l);
        }
        while(r<qr)
        {
            add(++r);
        }
        while(r>qr)
        {
            del(r--);
        }
        result[q[i].ord]=res;
    }
    for(register int i=0;i<qcnt;i++)
    {
        printf("%I64d\n",result[i]);
    }
}