#include <cstdio>

using namespace std;

int n,m,k,i,j;
bool s[100010];

struct nod
{
    int a,b;
} v[100010];
long long d[100010];

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for (i=1; i<=m; i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        v[i].a=x;
        v[i].b=y;
        d[i]=z;
    }
    for (i=1; i<=k; i++)
    {
        int x;
        scanf("%d", &x);
        s[x]=1;
    }
    long long minim=2000000000;
    for (i=1; i<=m; i++)
    {
        if (s[v[i].a]+s[v[i].b]==1&&d[i]<minim)
            minim=d[i];
    }
    printf("%lld", minim==2000000000 ? -1 : minim);
}