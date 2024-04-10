#include<bits/stdc++.h>
using namespace std;
int n,mi=0,a[400005],b[400005];
bool vis[400005];
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&b[i]),a[i]=a[i-1]+b[i],mi=min(mi,a[i]);
        if(a[i]>n)
        {
            printf("-1\n");return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        a[i]+=1-mi;
        if(a[i]>n) {printf("-1\n");return 0;}
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>n||vis[a[i]])
        {
            printf("-1\n");
            return 0;
        }
        vis[a[i]]=true;
    }
    for(int i=1;i<=n;i++)
        printf(i==n?"%d\n":"%d ",a[i]);
}