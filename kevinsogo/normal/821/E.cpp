#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define YY 21

ll m[YY][YY];
ll n[YY][YY];
void compute(ll x, ll c) {
    if (x == 0) {
        for (ll y = 0; y <= c; y++) {
            for (ll Y = 0; Y <= c; Y++) {
                m[y][Y] = y == Y;
            }
        }
    } else if (x & 1) {
        compute(x - 1, c);
        for (ll y = 0; y <= c; y++) {
            for (ll Y = 0; Y <= c; Y++) {
                n[y][Y] = m[y][Y];
                if (Y) n[y][Y] += m[y][Y-1];
                if (Y < c) n[y][Y] += m[y][Y+1];
                n[y][Y] %= mod;
            }
        }
        for (ll y = 0; y <= c; y++) {
            for (ll Y = 0; Y <= c; Y++) {
                m[y][Y] = n[y][Y];
            }
        }
    } else {
        compute(x >> 1, c);
        for (ll y = 0; y <= c; y++) {
            for (ll Y = 0; Y <= c; Y++) {
                n[y][Y] = 0;
                for (ll z = 0; z <= c; z++) {
                    n[y][Y] += m[y][z] * m[z][Y];
                    n[y][Y] %= mod;
                }
            }
        }
        for (ll y = 0; y <= c; y++) {
            for (ll Y = 0; Y <= c; Y++) {
                m[y][Y] = n[y][Y];
            }
        }
    }
}
ll ct[YY];
ll tp[YY];
void proceed(ll x, ll c) {
    compute(x, c);
    for (ll y = c+1; y < YY; y++) ct[y] = tp[y] = 0;
    for (ll Y = 0; Y <= c; Y++) {
        tp[Y] = 0;
        for (ll y = 0; y <= c; y++) {
            tp[Y] += ct[y] * m[y][Y];
            tp[Y] %= mod;
        }
    }
    for (ll y = 0; y <= c; y++) ct[y] = tp[y];
}

#define N 111
ll as[N];
ll bs[N];
ll cs[N];
int main() {
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    ct[0] = 1;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &as[i], &bs[i], &cs[i]);
    }
    bs[n-1] = min(bs[n-1], k);
    for (int i = 0; i < n; i++) {
        proceed(bs[i] - as[i], cs[i]);
    }
    printf("%lld\n", ct[0]);
}