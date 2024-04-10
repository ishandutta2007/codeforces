#include <bits/stdc++.h>

using namespace std;
long long plow(long long x,long long y){
    long long velik;
    if(y==0)return 1;
    velik=plow(x,y/2);
    velik%=1000000007;
    if(y%2==0)return (velik*velik)%1000000007;
    else return (x*((velik*velik)%1000000007)%1000000007);
}
int main()
{
    long long n,m;
    int k;
    cin>>n>>m>>k;
    if(k==-1 && n%2!=m%2){cout<<0;return 0;}
    cout<<plow(plow(2,(n-1)),(m-1));
    return 0;
}