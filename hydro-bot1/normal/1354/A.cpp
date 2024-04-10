// Hydro submission #62677d409f31360077e12d83@1650949440959
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,c,d,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b>>c>>d;
        if(a<=b)
        printf("%d\n",b);
        else if(c<=d)
        printf("-1\n");
        else
        printf("%lld\n",(long long)(ceil((a-b)*1.0/(c-d)))*c+b);
    }
    return 0;
}