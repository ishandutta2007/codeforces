// Hydro submission #62677dd49f31360077e12dac@1650949588375
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,b,s,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        s=0;
        cin>>a>>b>>n;
        while(a<=n&&b<=n)
        {
            a<b?a+=b:b+=a;
            s++;
        }
        printf("%d\n",s);
    }
    return 0;
}