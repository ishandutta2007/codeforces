#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int q;
map<ll,ll> v;

vector<ll> gp(ll x, ll y) {
    vector<ll> p;
    while (x != y) {
        if (x < y) swap(x,y);
        p.push_back(x);
        x /= 2;
    }
    return p;
}

int main() {
    scanf("%d", &q);
    FO(z,0,q) {
        int t; ll x, y; scanf("%d %lld %lld", &t, &x, &y);
        vector<ll> p = gp(x,y);
        if (t == 1) {
            ll w; scanf("%lld", &w);
            for (ll i : p) v[i] += w;
        } else {
            ll w = 0;
            for (ll i : p) w += v[i];
            printf("%lld\n", w);
        }
    }
}