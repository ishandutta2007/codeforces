#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[105],b[105];
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=3;i<=n-2;i++)
        if(a[i]==1&&a[i-1]==0&&a[i+1]==0&&a[i-2]==1&&a[i+2]==1) a[i]=0,ans++;
    for(int i=2;i<n;i++)
        if(a[i]==0&&a[i-1]==1&&a[i+1]==1) a[i+1]=0,ans++;
    printf("%d\n",ans);
}