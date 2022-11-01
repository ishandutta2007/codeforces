#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node
{
    int sum,rmx,lmx,mn,mx,d;
    node(int sum=0,int rmx=0,int lmx=0,int mn=0,int mx=0,int d=0):sum(sum),rmx(rmx),lmx(lmx),mn(mn),mx(mx),d(d){}
}t[4*N];
char s[N];
int n,k;
void update(int k)
{
    t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
    t[k].rmx=max(t[k<<1].rmx,max(t[k<<1|1].rmx-t[k<<1].sum,t[k<<1|1].mx+t[k<<1].sum-2*t[k<<1].mn));
    t[k].lmx=max(t[k<<1].lmx,max(t[k<<1|1].lmx-t[k<<1].sum,t[k<<1].mx-2*(t[k<<1|1].mn+t[k<<1].sum)));
    t[k].mn=min(t[k<<1].mn,t[k<<1|1].mn+t[k<<1].sum);
    t[k].mx=max(t[k<<1].mx,t[k<<1|1].mx+t[k<<1].sum);
    t[k].d=max(max(t[k<<1].d,t[k<<1|1].d),max(t[k<<1|1].rmx-t[k<<1].sum+t[k<<1].mx,t[k<<1].lmx+t[k<<1|1].mx+t[k<<1].sum));
}
void build(int l,int r,int k)
{
    if(l==r)
    {
        int x=s[l]=='('?1:-1;
        t[k]=node(x,-x,-x,x,x,0);
        return;
    }
    int m=l+r>>1;
    build(l,m,k<<1);
    build(m+1,r,k<<1|1);
    update(k);
}
void fix(int l,int r,int k,int x)
{
    if(l==r)
    {
        build(l,r,k);
        return;
    }
    int m=l+r>>1;
    if(x<=m) fix(l,m,k<<1,x);
    else fix(m+1,r,k<<1|1,x);
    update(k);
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    n=n*2-2;
    build(1,n,1);
    printf("%d\n",t[1].d);
    for(int i=1;i<=k;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        swap(s[l],s[r]);
        fix(1,n,1,l);
        fix(1,n,1,r);
        printf("%d\n",t[1].d);
    }
}