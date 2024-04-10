// Hydro submission #6267791d9f31360077e12aa4@1650948382860
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        printf("%d\n",min(n,n/k*k+k/2));
    }
    return 0;
}