#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);

    ll ans = (n-2)*(n*n+2*n+3)/3;
    printf("%lld", ans);
}