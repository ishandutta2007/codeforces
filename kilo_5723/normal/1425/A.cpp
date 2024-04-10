#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calc(ll n){
    if (!n) return 0;
    if (n==4) return 3;
    if ((n&1)||!(n&3)) return n-calc(n-1);
    return n-calc(n/2);
}
int main() {
    int tt;
    scanf("%d",&tt);
    while (tt--){
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",calc(n));
    }
    return 0;
}