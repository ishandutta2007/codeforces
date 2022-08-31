#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    ll a, b, s0;
    scanf("%d%lld%lld%lld", &n, &a, &b, &s0);
    vector<ll> s(n - 1);
    ll total = s0;
    for (int i = 0; i < n - 1; i++) {
        scanf("%lld", &s[i]);
        total += s[i];
    }
    sort(s.begin(), s.end());
    while (s0 * a < total * b) {
        total -= s.back(); s.pop_back();
    }
    printf("%d\n", n - 1 - int(s.size()));
}