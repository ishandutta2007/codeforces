#include <stdio.h>
#include <algorithm>
using namespace std;
   pair<int,int> a[100000]=make_pair(0,0);

    int ans[100000];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
            a[x].first++;
            a[x].second=i+1;
    }
    int av=0;
    for (int i=0;i<m;i++)
    {
        int b;
        scanf("%d",&b);
       // b--;
        if (a[b].first==0)
        {
            printf("Impossible");
            return 0;
        }
        if (a[b].first>1)
            av=1;
        else
            ans[i]=a[b].second;

    }
    if (av==1)
        printf("Ambiguity");
    else
    {
        printf("Possible\n");
        printf("%d",ans[0]);
        for (int i=1;i<m;i++)
            printf(" %d",ans[i]);
    }
    return 0;
}