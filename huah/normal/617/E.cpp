#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k,block,a[N];
long long res,ans[N];
int vis[20*N];
struct node
{
    int l,r,id;
}q[N];
int read()
{
    char c=getchar();int x=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x;
}
bool cmp(node p1,node p2)
{
    if(p1.l/block==p2.l/block)
        return p1.r<p2.r;
    return p1.l<p2.l;
}
void add(int x)
{
    //cout<<"ADD"<<x<<endl;
    res+=vis[a[x]^k];
    vis[a[x]]++;
}
void del(int x)
{
    //cout<<"DEL"<<x<<endl;
    vis[a[x]]--;
    res-=vis[a[x]^k];
}
int main()
{
    n=read();m=read();k=read();
    block=sqrt(n);
    for(int i=1;i<=n;i++)
        a[i]=read(),a[i]^=a[i-1];
    for(int i=1;i<=m;i++)
        q[i].l=read(),q[i].r=read(),q[i].id=i;
    sort(q+1,q+1+m,cmp);
    vis[0]=1;
    int l=0,r=0;
    for(int i=1;i<=m;i++)
    {
        while(l+1>q[i].l) add(--l);
        while(l+1<q[i].l) del(l++);
        while(r<q[i].r) add(++r);
        while(r>q[i].r) del(r--);
        ans[q[i].id]=res;
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
}