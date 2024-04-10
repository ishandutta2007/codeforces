#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],b[1000005],t[1000005];
int p[10000005];
map<int,int>pre;
struct node
{
    int l,r,id;
}k[1000005];
int ans[1000005];
void fix(int x,int l,int r)
{
    while(l<=r)
    {
        t[l]^=x;
        l+=(l&-l);
    }
}
int query(int x)
{
    if(x==0) return x;
    return t[x]^query(x-(x&-x));
}
bool cmp(node p1,node p2)
{
    return p1.r<p2.r;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),b[i]=a[i]^b[i-1];
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
        scanf("%d%d",&k[i].l,&k[i].r),k[i].id=i;
    sort(k+1,k+1+q,cmp);
    int s=1;
    for(int i=1;i<=n;i++)
    {
        int t;
        if(a[i]<=10000000) t=p[a[i]];
        else t=pre[a[i]];
        if(t) fix(a[i],t,n);
        fix(a[i],i,n);
        if(a[i]<=10000000) p[a[i]]=i;
        else
            pre[a[i]]=i;
        while(i==k[s].r&&s<=q)
        {
            ans[k[s].id]=query(k[s].l-1)^query(k[s].r)^b[i]^b[k[s].l-1];
            s++;
        }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
}