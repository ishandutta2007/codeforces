#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll n;
ll p[4] = {2, 3, 5, 7};

int main() {
    scanf("%lld", &n);
    ll ans = 0;
    for (int i = 0; i < (1<<4); i++) {
        int cnt = 0;
        ll cao = 1;
        for (int j = 0; j <4; j++) {
            if(i&(1<<j)) {
                cnt++;
                cao *= p[j];
            }
        }
        if (cnt&1) ans -= n / cao;
        else ans += n / cao;
    }
    printf("%lld\n", ans);
    return 0;
}