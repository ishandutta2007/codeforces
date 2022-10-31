// Hydro submission #62550759ac286d0a56b85f6c@1649739612673
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    printf("%d\n",min(a+b+c,min(2*a+2*b,min(2*b+2*c,2*a+2*c))));
    return 0;
}