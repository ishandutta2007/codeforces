// Hydro submission #62592056cc64917dc4665316@1650008158964
#include<bits/stdc++.h>
using namespace std;
int f[5001];
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>f[i];
    for(i=1;i<=n;i++)
    if(f[f[f[i]]]==i)
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}