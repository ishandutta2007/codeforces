#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[105],b[105];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(a[i]-b[i]!=0 && a[i]-b[i]!=-1) 
            {
                printf("NO\n");
                flag=false;
                break;
            }
        }
        if(flag) printf("YES\n");
    }
}