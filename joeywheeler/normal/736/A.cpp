#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    long long n, t, a=1, b=0, k=-2; scanf("%lld", &n);
    while (a <= n) {
        t = a;
        a += b;
        b = t;
        k++;
    }
    printf("%lld\n", k);
}