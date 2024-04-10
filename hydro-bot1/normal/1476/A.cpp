// Hydro submission #6274cd38bda16328ffbaf9b7@1651821881709
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        printf("%d\n",int(ceil(ceil(n*1.0/k)*k/n)));
    }
    return 0;
}