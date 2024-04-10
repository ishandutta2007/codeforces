// Hydro submission #62591c4237de167dd82bc3fc@1650007107025
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,d;
    cin>>n>>a>>b>>c;
    if(n==1) printf("0\n");
    else d=min(a,b),printf("%d\n",d>c?d+(n-2)*c:d*(n-1));
    return 0;
}