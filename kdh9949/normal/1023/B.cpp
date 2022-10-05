#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, k;

int main(){
    scanf("%lld%lld", &n, &k);
    printf("%lld\n", (max(0LL, min(n, k - 1) - max(1LL, k - n) + 1) -
        ((k % 2 == 0) && (k <= n * 2))) / 2);
}