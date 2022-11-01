#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

char s[1000005];
int n;

int main() {
    scanf(" %s", s);
    n = strlen(s);
    ll fln = n;
    ll nmb = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'b') {
            nmb++;
        } else {
            fln = (fln + nmb) % MOD;
            nmb = (nmb + nmb) % MOD;
        }
    }
    printf("%lld\n", (fln + MOD - n) % MOD);
}