#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int nxt[1000005];
int p, k;

int main() {
    scanf("%d%d", &p, &k);
    if (k == 0) {
        int x = (p-1);
        long long res = 1;
        FO(i,0,x) res = (res * p) % 1000000007;
        printf("%lld\n", res);
        return 0;
    }
    int g = k, t = 1;
    while (g != 1) {
        g = (g * 1ll * k) % p;
        t++;
    }
    assert((p-1)%t == 0);
    int x = (p-1)/t;
    long long res = 1;
    FO(i,0,x) res = (res * p) % 1000000007;
    if (k == 1) res = (res * 1ll * p) % 1000000007;
    printf("%lld\n", res);
}