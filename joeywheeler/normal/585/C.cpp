#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

stringstream s;

int main() {
    ll x, y; scanf("%lld %lld", &x, &y);
    while (x && y && x+y > 2) {
        if (x >= y) {
            ll v = x/y;
            // do v a's
            if (x-v*y == 0) v--;
            if (v == 0) break;
            s << v << 'A';
            x -= v*y;
        } else {
            ll v = y/x;
            // do v b's
            if (y-v*x == 0) v--;
            if (v == 0) break;
            s << v << 'B';
            y -= v*x;
        }
    }
    if (x == 1 && y == 1) {
        printf("%s\n", s.str().c_str());
    } else {
        printf("Impossible\n");
    }
}