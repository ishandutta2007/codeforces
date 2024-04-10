// Hydro submission #62677d989f31360077e12da4@1650949528140
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        if(a<b) swap(a,b);
        printf("%d\n",a>b*2?b:(a+b)/3);
    }
    return 0;
}