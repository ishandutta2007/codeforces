// Hydro submission #625ceb29fa9408d417fea8f1@1650256683281
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long s;
    int t,a,b,c,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s>>a>>b>>c;
        printf("%lld\n",s/c+s/c/a*b);
    }
    return 0;
}