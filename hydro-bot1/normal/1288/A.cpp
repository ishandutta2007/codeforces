// Hydro submission #62677954255d14008c299c57@1650948436713
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,d,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>d;
        printf(ceil(sqrt(d)*2)<=n+1?"YES\n":"NO\n");
    }
    return 0;
}