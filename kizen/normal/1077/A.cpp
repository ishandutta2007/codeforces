#include <bits/stdc++.h>

using namespace std;

long long t, a, b, k;

int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld %lld", &a, &b, &k);
        printf("%lld\n", (a-b)*(k/2)+(k%2)*a);
    }
    return 0;
}