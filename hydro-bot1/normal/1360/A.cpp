// Hydro submission #62677d7b9f31360077e12d97@1650949499843
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,s,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        s=min(max(a*2,b),max(a,b*2));
        printf("%d\n",s*s);
    }
    return 0;
}