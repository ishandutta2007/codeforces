// Hydro submission #625ced20fa9408d417feaa6b@1650257184319
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    long long c;
    cin>>a>>b>>c;
    printf("%lld\n",a==b?2*(a+c):2*min(a+c,b+c)+1);
    return 0;
}