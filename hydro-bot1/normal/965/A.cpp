// Hydro submission #6259211dcc64917dc4665465@1650008436761
#include<bits/stdc++.h>
using namespace std;
int main()
{
    float k,n,s,p;
    cin>>k>>n>>s>>p;
    printf("%d\n",int(ceil(ceil(n/s)*k/p)));
    return 0;
}