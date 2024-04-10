// Hydro submission #62591e3337de167dd82bc8e4@1650007604277
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,x;
    cin>>n>>a>>b;
    for(x=0;x*a<=n;x++)
    if((n-x*a)%b==0)
    {
        printf("YES\n%d %d\n",x,(n-x*a)/b);
        return 0;
    }
    printf("NO\n");
    return 0;
}