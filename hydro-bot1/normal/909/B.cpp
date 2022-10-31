// Hydro submission #62591e86cc64917dc46651eb@1650007695208
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    printf("%d\n",n&1?((n+1)*(n+1)/4):(n/2)*(n/2+1));
    return 0;
}