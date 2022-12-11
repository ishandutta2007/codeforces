#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=100000;
int n,m,k,y1,y2,maxv[MAXN*4][5],a[MAXN+5][5],_max[5];

void maintain(int o,int l,int r)
{
    if (l<r)
    {
        int lc=o*2,rc=o*2+1;
        for (int i=0;i<5;i++) maxv[o][i]=max(maxv[lc][i],maxv[rc][i]);
    }
    else for (int i=0;i<5;i++) maxv[o][i]=a[l][i];
}

void build(int o,int l,int r)
{
    if (l<r)
    {
        int m=(l+r)>>1;
        build(o*2,l,m);
        build(o*2+1,m+1,r);
    }
    maintain(o,l,r);
}

void query(int o,int l,int r)
{
    if (y1<=l&&y2>=r) for (int i=0;i<m;i++) _max[i]=max(_max[i],maxv[o][i]);
    else
    {
        int m=(l+r)>>1;
        if (y1<=m) query(o*2,l,m);
        if (y2>m) query(o*2+1,m+1,r);
    }
}

bool check(int l,int r)
{
    y1=l;y2=r;
    memset(_max,0,sizeof(_max));
    query(1,1,n);
    int cnt=0;
    for (int i=0;i<m;i++) cnt+=_max[i];
    return cnt<=k;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    build(1,1,n);
    int ans=0,al=0,ar=0;
    for (int i=1;i<=n;i++)
    {
        int l=1,r=i,cnt=0;
        while (l<=r)
        {
            int m=(l+r)>>1;
            if (check(m,i))
            {
                cnt=i-m+1;
                r=m-1;
            }
            else l=m+1;
        }
        if (cnt>ans)
        {
            ans=cnt;
            ar=i;al=i-cnt+1;
        }
    }
    if (!al)
    {
        for (int i=0;i<m;i++) printf("0 ");
        return 0;
    }
    y1=al;y2=ar;
    memset(_max,0,sizeof(_max));
    query(1,1,n);
    for (int i=0;i<m;i++) printf("%d ",_max[i]);
    return 0;
}