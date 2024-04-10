// Hydro submission #62677ca19f31360077e12c61@1650949281356
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        printf(n==1||m==1||n==2&&m==2?"YES\n":"NO\n");
    }
    return 0;
}