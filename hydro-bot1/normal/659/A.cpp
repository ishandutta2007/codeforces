// Hydro submission #62550bc2ac286d0a56b865e5@1649740739263
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,k;
    cin>>n>>a>>b;
    k=a+b;
    while(k<=0) k+=n;
    while(k>n) k-=n;
    printf("%d\n",k);
    return 0;
}