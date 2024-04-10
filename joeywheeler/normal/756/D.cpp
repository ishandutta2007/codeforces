#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

typedef long long ll;

int n;
char s[5005];
ll f[5005];
ll v[26];
ll sv;

int main() {
    scanf("%d", &n);
    scanf(" %s", s);
    FO(i,0,n) f[i] = 1;
    for (int i = n-1; i >= 0; i--) {
        sv = 0;
        FO(j,0,26) v[j] = 0;
        for (int j = n-1; j >= 0; j--) {
            sv -= v[s[j]-'a'];
            v[s[j]-'a'] = f[j];
            sv += v[s[j]-'a'];
            while (sv < 0) sv += MOD;
            while (sv >= MOD) sv -= MOD;
            f[j] = sv;
        }
    }
    printf("%lld\n", f[0]);
}