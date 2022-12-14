#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    while(N--){
        long long a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
        if(b*2<=c) printf("%lld\n", a*b);
        else printf("%lld\n", a/2*c+a%2*b);
    }
    return 0;
}