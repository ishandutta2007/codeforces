#include <cstdio>
#include <cstdlib>

const int MAXN=1005;

struct Point
{
    int x,y;
}p[MAXN];

int x0,y0;
bool vis[MAXN];

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

bool judge(Point a,Point b)
{
    int x1=a.x-x0,y1=a.y-y0,x2=b.x-x0,y2=b.y-y0;
    if ((x1*y1>0)!=(x2*y2>0)) return false;
    x1=abs(x1);y1=abs(y1);x2=abs(x2);y2=abs(y2);
    int g1=gcd(x1,y1),g2=gcd(x2,y2);
    if ((x1/g1==x2/g2)&&(y1/g1==y2/g2)) return true;
    return false;
}

int main()
{
    int f1=0,f2=0,ans=0,n;
    scanf("%d%d%d",&n,&x0,&y0);
    for (int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
    for (int i=0;i<n;i++)
        if (!vis[i])
        {
            vis[i]=true;
            if (p[i].x==x0)
            {
                f1=1;
                continue;
            }
            if (p[i].y==y0)
            {
                f2=1;
                continue;
            }
            ans++;
            for (int j=0;j<n;j++)
                if (!vis[j])
                    if (judge(p[i],p[j])) vis[j]=true;
        }
    printf("%d",ans+f1+f2);
    return 0;
}