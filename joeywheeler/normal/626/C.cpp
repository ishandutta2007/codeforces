#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    long long s = 0, e = 1e16, b = 1e16;
    while (s <= e) {
        long long md = (s+e)/2;
        long long two = md/2 - md/6;
        long long three = md/3 - md/6;
        long long both = md/6;
        long long nn = max(n-two,0ll);
        long long mm = max(m-three,0ll);
        if (nn+mm <= both) {
            b = md;
            e = md-1;
        } else {
            s = md+1;
        }
    }
    printf("%lld\n", b);
}