#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a=0,b=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x%2) a++;
        else b++;
    }
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        if(x%2&&b) b--,ans++;
        else if(x%2==0&&a) a--,ans++;
    }
    printf("%d\n",ans);
}