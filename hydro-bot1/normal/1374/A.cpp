// Hydro submission #62677e149f31360077e12de8@1650949653050
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,n,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x>>y>>n;
        printf("%d\n",(n-y)-(n-y)%x+y);
    }
    return 0;
}