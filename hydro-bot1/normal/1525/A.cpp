// Hydro submission #6274d067997df5291339dc86@1651822695436
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,k,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>k;
        printf("%d\n",100/__gcd(k,100));
    }
    return 0;
}