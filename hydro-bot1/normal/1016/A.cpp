// Hydro submission #625cea5a81ef68d42bcba94d@1650256475323
#include<bits/stdc++.h>
using namespace std;
long long s;
int main()
{
    int n,m,a,i;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a;
        s+=a;
        printf("%lld ",s/m);
        s%=m;
    }
    return 0;
}