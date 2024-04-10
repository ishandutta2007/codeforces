#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2==0)
                ans=i;
        }
        if(ans!=-1) printf("1\n%d\n",ans);
        else
        {
            int f1=-1,f2=-1;
            for(int i=1;i<=n;i++) if(a[i]&1) {f1=i;break;}
            for(int i=n;i>=1;i--) if(a[i]&1){f2=i;break;}
            if(f1==f2) printf("-1\n");
            else printf("2\n%d %d\n",f1,f2);
        }
    }
}