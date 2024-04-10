#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, p;
typedef long long ll;

int main() {
    scanf("%d%d", &n, &p);
    ll r = 0;
    FO(i,0,n) {
        string s; cin >> s;
        if (sz(s) > 4) {
            r |= 1ll << i;
        }
    }
    printf("%lld\n", r*p - p/2 * __builtin_popcountll(r));
}