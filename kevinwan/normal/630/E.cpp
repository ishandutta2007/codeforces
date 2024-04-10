#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    c-=a,d-=b;
    if(c&1){
        printf("%lld",(c+1)*(d+1)/2);
    }
    else{
        printf("%lld",(c/2+1)*(d/2+1)+(c/2)*(d/2));
    }
}