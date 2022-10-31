// Hydro submission #631f3132bdf9bc31d15c8481@1662988595092
#include<bits/stdc++.h>
using namespace std;
long long C(int n,int k)
{
    long long s=1;
    for(int i=1;i<=k;i++)
    s=s*(n-i+1)/i;
    return s;
}
int main()
{
    int n;
    cin>>n;
    printf("%lld\n",C(n,7)+C(n,6)+C(n,5));
    return 0; 
}