#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,t,a[100005],b[100005];
bool cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=i;
        }
        sort(b+1,b+n+1,cmp);
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(b[i]!=b[i+1]-1) ans++;
        }
//        printf("%d\n",ans);
        if(ans>k) printf("No\n");
        else printf("Yes\n");
    }
}