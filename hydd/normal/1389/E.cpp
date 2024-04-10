#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int gcd(int a,int b){
    if (!b) return a;
    return gcd(b,a%b);
}
ll calc(int n){
    return 1ll*n*(n-1)>>1;
}
int main(){
    scanf("%d",&T);
    while (T--){
        int m,d,w;
        scanf("%d%d%d",&m,&d,&w);
        int t=w/gcd(w,d-1),l=min(m,d);
        printf("%lld\n",calc(l/t+1)*(l%t)+calc(l/t)*(t-l%t));
    }
    return 0;
}