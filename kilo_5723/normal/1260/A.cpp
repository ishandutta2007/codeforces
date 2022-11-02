#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main(){
    int tt;
    ll a,b;
    scanf("%d",&tt);
    while (tt--){
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",(b/a+1)*(b/a+1)*(b%a)+(b/a)*(b/a)*(a-b%a));
    }
    return 0;
}