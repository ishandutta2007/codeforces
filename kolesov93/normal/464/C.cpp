#include <iostream>
#include <stdio.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);
const int N = 2000555;
const int MOD = 1000000007;
char buffer[N];
int first[N];
char s[N];
int last;
int n;

ll len[11], md[11];

ll powmod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    gets(s);
    last = 0;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        first[i] = last;
        gets(buffer + last);
        while (buffer[last]) ++last;
        ++last;
    }

    for (int d = 0; d < 10; ++d) {
        len[d] = 1;
        md[d] = d;
    }

    for (int it = n - 1; it >= 0; --it) {
        int d = buffer[first[it]] - '0';

        ll nlen = 0;
        int pointer_i = first[it] + 1;
        while (buffer[pointer_i] != '>') ++pointer_i;
        ++pointer_i;
        int beg = pointer_i;
        while (buffer[pointer_i]) ++pointer_i;
        int en = pointer_i;

        ll nmod = 0;
        for (int i = en - 1; i >= beg; --i) {
            nmod = (nmod + powmod(10, nlen) * md[ buffer[i] - '0' ]) % MOD;
            nlen = (nlen + len[ buffer[i] - '0' ]) % (MOD - 1);
        }
        len[d] = nlen;
        md[d] = nmod;
    }

    int pointer_i = 0;
    while (s[pointer_i]) ++pointer_i;

    ll ans = 0;
    ll clen = 0;
    for (int i = pointer_i - 1; i >= 0; --i) {
        ans = (ans + powmod(10, clen) * md[ s[i] - '0' ]) % MOD;
        clen = (clen + len[ s[i] - '0']) % (MOD - 1);
    }

    cout << ans << endl;

    return 0;
}