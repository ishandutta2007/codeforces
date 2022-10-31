// Hydro submission #62be4d9a89ffbb18f0fdacc1@1656638875129
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,c,d;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        printf("%d\n",(b>a)+(c>a)+(d>a));
    }
    return 0;
}