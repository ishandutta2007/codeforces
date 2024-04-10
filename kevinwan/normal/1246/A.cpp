#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,p;
    scanf("%lld%lld",&n,&p);
    for(ll i=0;n>0;i++,n-=p){
        if(__builtin_popcount(n)<=i&&n>=i){
            printf("%lld",i);
            return 0;
        }
    }
    printf("-1");
}
//Since the beginning of time, humans have believed that TRUE SARVESH will lead us to the state of TRUE SARVESHISM. All Hail Sarvesh!
//Since the beginning of time,