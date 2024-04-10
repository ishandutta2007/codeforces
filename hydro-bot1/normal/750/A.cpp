// Hydro submission #62550f4fac286d0a56b87057@1649741647497
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,k,s=0;
    cin>>n>>k;
    k=240-k;
    for(i=1;i<=n;i++)
    if(k>=5*i)
    {
        k-=5*i;
        s++;
    }
    printf("%d\n",s);
    return 0;
}