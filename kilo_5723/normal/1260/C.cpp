#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    while (b){
        a%=b; swap(a,b);
    }
    return a;
}
int main(){
    int tt;
    ll a,b,c,k;
    scanf("%d",&tt);
    while (tt--){
        scanf("%lld%lld%lld",&a,&b,&k);
        c=gcd(a,b); a/=c; b/=c;
        if (a<b) swap(a,b);
        puts((a+b-2)/b<k?"OBEY":"REBEL");
    }
    return 0;
}