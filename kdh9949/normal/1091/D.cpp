#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = 1000005, M = 998244353;

ll n, c[N], d[N];

int main(){
    scanf("%lld", &n);
    c[0] = 1;
    for(int i = 1; i <= n; i++) c[i] = c[i - 1] * i % M;
    for(int i = 3; i <= n; i++) d[i] = i * (d[i - 1] + c[i - 1] + M - 1) % M;
    printf("%lld\n", (c[n] + d[n]) % M);
}