#include <bits/stdc++.h>
using namespace std;

const int MAXN=1005;

int main()
{
    int n;
    char a[MAXN],b[MAXN];
    scanf("%d%s%s",&n,a,b);
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]>b[i]) swap(a[i],b[i]);
        ans+=min(b[i]-a[i],a[i]+10-b[i]);
    }
    printf("%d",ans);
    return 0;
}