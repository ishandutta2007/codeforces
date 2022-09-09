#include<cstdio>
using namespace std;
int t,n;
long long tmp=1,a[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        bool flag=false;
        tmp=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            bool tflag=false;
            for(int j=2;j<=100 && j<=i+1;j++)
            {
                if(a[i]%j!=0) tflag=true;
            }
            if(!tflag) flag=true;
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
}