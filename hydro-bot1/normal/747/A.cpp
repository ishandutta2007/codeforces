// Hydro submission #62550f38ac286d0a56b86fc8@1649741629531
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    for(i=sqrt(n);i;i--)
    if(n%i==0)
    {
        printf("%d %d\n",i,n/i);
        return 0;
    }
    return 0;
}