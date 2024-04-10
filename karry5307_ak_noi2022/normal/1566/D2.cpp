#include<cstdio>
#include<algorithm>
using namespace std;
int ans,n,m,t,f[305][305];
struct node
{
    int val,id;
    int R,C;
}a[100005];
bool cmp(node x,node y){return x.val != y.val ? x.val<y.val : x.id<y.id;}
bool cmp2(node x,node y){return x.id<y.id;}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) f[i][j]=0;
        for(int i=1;i<=n*m;i++) a[i].R=a[i].C=0;
        for(int i=1;i<=n*m;i++)
        {
            scanf("%d",&a[i].val);
            a[i].id=i;
        }
        sort(a+1,a+n*m+1,cmp);
        ans=0;
        a[0].C=m;
        for(int i=1;i<=n*m;i++)
        {
            a[i].R=(a[i-1].C==m ? a[i-1].R+1 : a[i-1].R);
            a[i].C=(a[i-1].C==m ? 1 : a[i-1].C+1);
        }
        sort(a+1,a+n*m+1,cmp2);
        for(int i=1;i<=n*m;i++)
        {
            for(int j=1;j<=a[i].C;j++)
            {
                if(f[a[i].R][j]!=a[i].val && f[a[i].R][j]!=0) ans++;
            }
            f[a[i].R][a[i].C]=a[i].val;
        }
        printf("%d\n",ans);
    }
}