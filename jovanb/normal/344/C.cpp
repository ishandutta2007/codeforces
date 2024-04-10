#include <bits/stdc++.h>
using namespace std;

long long br=0;

void gcd(long long x,long long y){
    if(y>x)swap(x,y);
    if(y==0)return;
    br+=x/y;
    gcd(y,x%y);
}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long a,b;
    cin>>a>>b;
    gcd(a,b);
    cout<<br;
    return 0;
}