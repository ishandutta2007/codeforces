// Hydro submission #6267785c255d14008c299ab1@1650948189495
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,x,a,b,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>x>>a>>b;
        printf("%d\n",min(n-1,abs(a-b)+x));
    }
    return 0;
}