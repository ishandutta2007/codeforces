// Hydro submission #6274cee7997df5291339d84b@1651822312046
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,i;
    long long x;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m>>x;x--;
        printf("%lld\n",x%n*m+x/n+1);
    }
    return 0;
}