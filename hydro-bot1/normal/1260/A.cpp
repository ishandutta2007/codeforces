// Hydro submission #6267787b9f31360077e129df@1650948220085
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c,s,m,l,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c>>s;
        m=s/c;l=s%c;
        printf("%d\n",(m+1)*(m+1)*l+m*m*(c-l));
    }
    return 0;
}