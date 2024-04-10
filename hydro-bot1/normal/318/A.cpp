// Hydro submission #6253d17348f78301327927a6@1649660276024
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,s;cin>>n>>k;s=ceil(n/2.0);
    if(k>s) printf("%lld\n",(k-s)*2);
    else printf("%lld\n",k*2-1);
    return 0;
}