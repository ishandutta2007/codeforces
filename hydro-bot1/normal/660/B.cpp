// Hydro submission #631f2e28bdf9bc31d15c7ee3@1662987816472
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i;
    cin>>n>>m;
    n*=2;
    for(i=1;i<=n;i++)
    {
        if(i+n<=m)
        printf("%d ",i+n);
        if(i<=m)
        printf("%d ",i);
    }
    return 0;
}