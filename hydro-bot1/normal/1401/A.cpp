// Hydro submission #6274c9a8997df5291339c8dd@1651820969868
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        printf("%d\n",n<k?k-n:(n+k)%2);
    }
    return 0;
}