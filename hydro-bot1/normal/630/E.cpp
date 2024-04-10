// Hydro submission #631f311632ae6c3198c910f9@1662988567276
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    printf("%lld\n",((y2-y1)/2+1)*(x2-x1+1)-(x2-x1)/2);
    return 0;
}