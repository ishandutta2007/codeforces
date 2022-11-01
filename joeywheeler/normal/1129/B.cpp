#include <bits/stdc++.h>

#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int main() {
    ll k; scanf("%lld", &k);
    int l = 1800;
    ll a = ((-k) % (l+1) + (l+1)) % (l+1);
    ll b = (k + a * (l+2)) / (l+1);
    assert((b-a) * (l+2) == k + b);
    assert(abs(b) <= 1000000);
    printf("%d\n", l+2);
    fo(i,0,l) printf("0 ");
    printf("%lld %lld\n", -a, b);
}