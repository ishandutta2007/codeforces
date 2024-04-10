#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,w,d;
int main(){
    cin >> n >> p >> w >> d;
    for(ll v=0;v<w;v++){
        if((p - v * d) % w == 0){
            ll x = (p - v * d) / w;
            if(x >= 0 && x + v <= n){
                printf("%lld %lld %lld\n",x,v,n-x-v);
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}