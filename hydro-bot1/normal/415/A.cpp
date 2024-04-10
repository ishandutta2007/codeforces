// Hydro submission #62ef205a74296d3511bba702@1659838555184
#include<bits/stdc++.h>
using namespace std;
int f[101];
int main()
{
    int n,m,k,i,j;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>k;
        for(j=k;j<=n&&!f[j];j++)
        f[j]=k;
    }
    for(i=1;i<=n;i++)
    printf("%d ",f[i]);
    return 0;
}