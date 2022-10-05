#include <bits/stdc++.h>
using namespace std;

using ll=long long;

ll n;

int main(){
    scanf("%lld", &n);
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){ printf("%lld\n", 1+(n-i)/2); return 0; }
    }
    puts("1");
}