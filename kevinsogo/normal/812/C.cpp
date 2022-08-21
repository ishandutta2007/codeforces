#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N 111111

ll a[N];
ll b[N];
int n;
ll cost(ll k) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i] + (i + 1) * k;
    }
    sort(b, b + n);
    ll gastos = 0;
    for (int i = 0; i < k; i++) gastos += b[i];
    return gastos;
}
int main() {
    ll s;
    scanf("%d%lld", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int L = 0, R = n + 1;
    ll cL = 0;
    while (R - L > 1) {
        int M = L + R >> 1;
        ll cM = cost(M);
        if (cM <= s) {
            L = M;
            cL = cM;
        } else {
            R = M;
        }
    }
    printf("%d %lld\n", L, cL);
}