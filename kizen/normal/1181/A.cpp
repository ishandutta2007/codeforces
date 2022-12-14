#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
    long long ans = a / c + b / c, ans2 = 0;
    a %= c, b %= c;
    if(a + b >= c){
        ++ans, ans2 = min(c - a, c - b);
    }
    printf("%lld %lld\n", ans, ans2);
    return 0;
}