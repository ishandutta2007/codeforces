#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll a, b;
vector<ll> v;

void go(ll x) {
    v.push_back(x);
    if (x == b) {
        printf("YES\n");
        printf("%d\n", sz(v));
        for (ll u : v) printf("%lld ", u);
        exit(0);
    }
    if (x < b) {
        go(2*x);
        go(10*x+1);
    }
    v.pop_back();
}

int main() {
    scanf("%lld %lld", &a, &b);
    go(a);
    printf("NO\n");
}