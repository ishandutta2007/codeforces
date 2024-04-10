// Hydro submission #62550c1217cd4d0a41764bea@1649740819155
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,s=0,h,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>h;
        if(h>k)
        s++;
    }
    printf("%d\n",s+n);
    return 0;
}