// Hydro submission #631f317232ae6c3198c911f3@1662988659931
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;cin>>n;
    n*=(n-1)*(n-2)*(n-3)*(n-4);
    printf("%lld\n",n/120*n);
    return 0;
}