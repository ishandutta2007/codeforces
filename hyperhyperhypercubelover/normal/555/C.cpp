#include<cstdio>
#include<algorithm>

int x[222222];
int y[222222];
int d[222222];

int tx[222222];
int ty[222222];

struct node
{
    int l,r,s,e,x;
};

struct tree
{
    int tn;
    node a[444444];

    void init(int i,int s,int e)
    {
        a[i].s=s;
        a[i].e=e;
        a[i].x=1e9;
        if(s<e)
        {
            a[i].l=++tn;
            a[i].r=++tn;
            init(a[i].l,s,(s+e)/2);
            init(a[i].r,(s+e)/2+1,e);
        }
    }

    int upd(int i,int x,int y)
    {
        if(a[i].s>x||a[i].e<x)return a[i].x;
        if(a[i].s==x&&x==a[i].e)return a[i].x=y;
        return a[i].x=std::min(upd(a[i].l,x,y),upd(a[i].r,x,y));
    }

    int get(int i,int s,int e)
    {
        if(s<a[i].s)s=a[i].s;
        if(e>a[i].e)e=a[i].e;
        if(s>e)return 1e9;
        if(s==a[i].s&&e==a[i].e)return a[i].x;
        return std::min(get(a[i].l,s,e),get(a[i].r,s,e));
    }
} T[2];

char s[4];

int main()
{
    int l,r,mid;
    int i,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%s",&x[i],&y[i],s);
        if(s[0]=='L')d[i]=1;
        tx[i]=x[i];
        ty[i]=y[i];
    }
    T[0].init(0,0,m);
    T[1].init(0,0,m);
    T[0].upd(0,0,0);
    T[1].upd(0,0,0);
    std::sort(tx+1,tx+m+1);
    std::sort(ty+1,ty+m+1);
    for(i=1;i<=m;i++)
    {
        x[i]=std::lower_bound(tx+1,tx+m+1,x[i])-tx;
        y[i]=std::lower_bound(ty+1,ty+m+1,y[i])-ty;
        if(d[i])
        {
            if(T[1].get(0,y[i],y[i])<1e9)
            {
                puts("0");
                continue;
            }
            l=0;
            r=x[i];
            while(l<r)
            {
                mid=(l+r+1)/2;
                if(T[0].get(0,mid,x[i])>y[i])r=mid-1;
                else l=mid;
            }
            T[1].upd(0,y[i],l);
            printf("%d\n",tx[x[i]]-tx[l]);
        }
        else
        {
            if(T[0].get(0,x[i],x[i])<1e9)
            {
                puts("0");
                continue;
            }
            l=0;
            r=y[i];
            while(l<r)
            {
                mid=(l+r+1)/2;
                if(T[1].get(0,mid,y[i])>x[i])r=mid-1;
                else l=mid;
            }
            T[0].upd(0,x[i],l);
            printf("%d\n",ty[y[i]]-ty[l]);
        }
    }
}