// Hydro submission #62677b749f31360077e12b71@1650948980702
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,i;
    cin>>a;
    for(i=2;i<=sqrt(a);i++)
    if(a%i==0)
    printf("%d%d\n",i,a/i);
    return 0;
}