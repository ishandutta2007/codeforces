// Hydro submission #62ef225e74879b352565dc0b@1659839071243
#include<bits/stdc++.h>
#define calc(a,b,c) a>max(b,c)?0:max(b,c)-a+1
using namespace std;
int main()
{
    int t,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        printf("%d %d %d\n",calc(a,b,c),calc(b,a,c),calc(c,a,b));
    }
    return 0;
}