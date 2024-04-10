// Hydro submission #626779949f31360077e12ad4@1650948501264
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,c,n,s,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b>>c>>n;
        s=a+b+c+n;
        printf(s%3||a>s/3||b>s/3||c>s/3?"NO\n":"YES\n");
    }
    return 0;
}