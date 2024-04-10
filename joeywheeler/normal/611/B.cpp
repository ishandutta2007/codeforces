#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll a, b;

int main() {
    scanf("%lld %lld", &a, &b);
    int c = 0;
    for (int i = 1; i < 63; i++) {
        for (int j = 0; j < i-1; j++) {
            ll x = (1ll << i) - 1 - (1ll << j);
            c += a <= x && x <= b;
        }
    }
    printf("%d\n", c);
}