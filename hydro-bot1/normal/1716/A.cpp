// Hydro submission #62ef229b74296d3511bba8e5@1659839131536
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        printf("%d\n",int(ceil(n/3.0))+(n==1));
    }
    return 0;
}