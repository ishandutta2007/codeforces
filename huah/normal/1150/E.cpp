#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
struct node
{
    int dis,a,b,lm,lp,rm,rp;
    node(){a=b=0;dis=lm=lp=rm=rp=0;}
}t[N<<2];
int n,m,tot=1;
char s[N];
void update(int l,int k)
{
    t[k]=node();
    if(s[l]=='(')
    {
        t[k].b=1;
        t[k].lp=t[k].rp=1;
        t[k].lm=1;t[k].rm=-1;
    }
    else if(s[l]==')')
    {
        t[k].a=1;
        t[k].lp=t[k].rp=1;
        t[k].lm=-1;t[k].rm=1;
    }
}
node Merge(node a,node b)
{
    node ans=node();
    if(a.b>b.a) ans.a=a.a,ans.b=b.b+a.b-b.a;
    else ans.a=a.a+b.a-a.b,ans.b=b.b;
    ans.dis=max(max(a.dis,b.dis),max(a.rp+b.lm,a.rm+b.lp));
    ans.lp=max(a.lp,max(a.a-a.b+b.lp,a.a+a.b+b.lm));
    ans.rp=max(b.rp,max(b.a+b.b+a.rm,b.b-b.a+a.rp));
    ans.lm=max(a.lm,a.b-a.a+b.lm);
    ans.rm=max(b.rm,b.a-b.b+a.rm);
    return ans;
}
void build(int l,int r,int k)
{
    if(l==r)
    {
        update(l,k);return;
    }
    int m=l+r>>1;
    build(l,m,k<<1);build(m+1,r,k<<1|1);
    t[k]=Merge(t[k<<1],t[k<<1|1]);
}
void fix(int l,int r,int k,int x)
{
    if(l==r) {update(l,k);return;}
    int m=l+r>>1;
    if(x<=m) fix(l,m,k<<1,x);
    else fix(m+1,r,k<<1|1,x);
    t[k]=Merge(t[k<<1],t[k<<1|1]);
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    n=strlen(s+1);
    build(1,n,1);
    printf("%d\n",t[1].dis);
    while(m--)
    {

        int x,y;
        scanf("%d%d",&x,&y);
        swap(s[x],s[y]);
        fix(1,n,1,x);
        fix(1,n,1,y);
        printf("%d\n",t[1].dis);
    }
}