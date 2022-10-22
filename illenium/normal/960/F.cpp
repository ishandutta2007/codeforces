#include<cstdio>
#include<algorithm>
#define lowbit(x) (x&-x)
using namespace std;

const int maxn=100010;
int n,m,f[maxn],rt[maxn],sz;
struct tree{int l,r,mx;}t[maxn*20];

void insert(int &k,int l,int r,int x,int y)
{
    if(!k)k=++sz;t[k].mx=max(t[k].mx,y);
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x<=mid)insert(t[k].l,l,mid,x,y);
    else insert(t[k].r,mid+1,r,x,y);
}

int query(int k,int l,int r,int x)
{
    if(l==r)return t[k].mx;
    int mid=(l+r)>>1;
    if(x<=mid)return query(t[k].l,l,mid,x);
    else return max(t[t[k].l].mx,query(t[k].r,mid+1,r,x));
}

int main()
{
	scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=1;i<=m;i++)
	{
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        f[i]=query(rt[u],1,100000,w-1)+1;
        insert(rt[v],1,100000,w,f[i]);
        ans=max(ans,f[i]);
    }
    printf("%d",ans);
    return 0;

}