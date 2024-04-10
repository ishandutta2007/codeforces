#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    long long res = 0;
    FO(z,0,k) {
        if (n <= 1) break;
        res += 2*(n-2)+1;
        n -= 2;
    }
    printf("%lld\n", res);
}