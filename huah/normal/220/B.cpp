#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,res,block,a[N],ans[N],vis[N];
struct node
{
    int l,r,id;
    bool operator<(const node&o)const
    {
        if(l/block==o.l/block) return r<o.r;
        return l/block<o.l/block;
    }
}p[N];
void add(int x)
{
    if(x==0) return;
    if(a[x]>n) return;
    vis[a[x]]++;
    if(vis[a[x]]==a[x]) res++;
    else if(vis[a[x]]==a[x]+1) res--;
}
void del(int x)
{
    if(x==0) return;
    if(a[x]>n) return;
    vis[a[x]]--;
    if(vis[a[x]]==a[x]) res++;
    if(vis[a[x]]==a[x]-1) res--;
}
int main()
{
    int t=1;
    for(int cas=1;cas<=t;cas++)
    {
        memset(vis,0,sizeof(vis));
        res=0;
        scanf("%d%d",&n,&q);
        block=sqrt(n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=q;i++)
            scanf("%d%d",&p[i].l,&p[i].r),p[i].id=i;
        sort(p+1,p+1+q);
        int l=0,r=0;
        for(int i=1;i<=q;i++)
        {
            while(l<p[i].l) del(l++);
            while(l>p[i].l) add(--l);
            while(r>p[i].r) del(r--);
            while(r<p[i].r) add(++r);
            ans[p[i].id]=res;
        }
        for(int i=1;i<=q;i++)
            printf("%d\n",ans[i]);
    }
}