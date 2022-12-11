#include <cstdio>
#include <algorithm>
using namespace std;

struct task
{
    int no,v;
}a[2000];

bool cmp(task c,task d)
{
    return c.v<d.v;
}
int main()
{
    int n,cnt=0,num[3];
    bool flag=false;
    scanf("%d",&n);
    for (int i=0;i<n;i++) 
    {
        scanf("%d",&a[i].v);
        a[i].no=i;
    }
    sort(a,a+n,cmp);
    for (int i=1;i<n;i++)
      if (a[i].v==a[i-1].v) 
      {
        num[cnt++]=i;
        if (cnt>=2)
        {
            flag=true;
            break;
        }
      }
    if (flag)
    {
        printf("YES\n");
        for (int i=0;i<n;i++) printf("%d ",a[i].no+1);
        printf("\n");
        for (int i=0;i<num[0]-1;i++) printf("%d ",a[i].no+1);
        printf("%d %d ",a[num[0]].no+1,a[num[0]-1].no+1);
        for (int i=num[0]+1;i<n;i++) printf("%d ",a[i].no+1);
        printf("\n");
        for (int i=0;i<num[1]-1;i++) printf("%d ",a[i].no+1);
        printf("%d %d ",a[num[1]].no+1,a[num[1]-1].no+1);
        for (int i=num[1]+1;i<n;i++) printf("%d ",a[i].no+1);
    }
    else printf("NO");
    return 0;
}