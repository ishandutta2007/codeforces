#include<bits/stdc++.h>
#define LL long long
using namespace std;

int T,n,m,a[2000010],b[2000010];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            a[i]=0;
        int x;
        for (int i=1;i<=n;i++)
            scanf("%d",&x),a[x]++;
        int Min=n,s=0;
        for (int i=1;i<=n;i++)
            if (a[i]>0) b[++s]=a[i],Min=min(Min,a[i]);
        int ans=n;
        for (int i=1;i<=Min+2;i++)
        {
            int flag=0,res=0;
            for (int j=1;j<=s;j++)
            {
                int k=b[j]/(i+1),p=n+1;
                if (k*i<=b[j]&&k*(i+1)>=b[j]) p=min(p,k);
                if ((k-1)*i<=b[j]&&(k-1)*(i+1)>=b[j]) p=min(p,k-1);
                if ((k+1)*i<=b[j]&&(k+1)*(i+1)>=b[j]) p=min(p,k+1);
                if (p==n+1) flag=1;
                else res+=p;
            }
            if (!flag) ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}