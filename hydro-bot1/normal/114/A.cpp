// Hydro submission #6253bfd1ca530601467154ab@1649655762296
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,l,n;
    cin>>k>>l;
    for(n=1;pow(k,n)<=l;n++)
    if(pow(k,n)==l)
    {
        printf("YES\n%d\n",n-1);
        return 0;
    }
    printf("NO\n");
    return 0;
}