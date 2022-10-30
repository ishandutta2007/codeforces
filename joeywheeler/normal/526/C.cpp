#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll w[2], h[2];
ll c;

ll calc(ll na) {
    ll wa = w[0] * na;
    if (wa > c) return -1;
    ll nb = (c - wa) / w[1];
    return h[0] * na + h[1] * nb;
}

int main() {
    scanf("%lld", &c);
    FO(i,0,2) scanf("%lld", h+i);
    FO(i,0,2) scanf("%lld", w+i);

    ll res = 0;
    for (ll i = 0; i*i <= 2000000000ll; i++) res = max(res,calc(i));
    swap(w[0],w[1]);
    swap(h[0],h[1]);
    for (ll i = 0; i*i <= 2000000000ll; i++) res = max(res,calc(i));
    printf("%lld\n", res);
}