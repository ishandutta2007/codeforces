#include<bits/stdc++.h>
using namespace std;
#define N 100010
char s[N], t[N];
int nx[N];
namespace Hash {
    #define LL long long
    LL ht[N], hs[N],pw[N], md = 998244853;
    bool cmp(int l, int len) {
        return (hs[l + len - 1] - hs[l - 1] * pw[len] % md+md) % md == ht[len];
    }
    void Init(int S, int T) {
        for (int i = 1;i <= T;i++) {
            ht[i] = (ht[i - 1] * 29 + (LL)t[i]) % md;
        }
        pw[0] = 1;
        for (int i = 1;i <= S;i++) {
            pw[i] = pw[i - 1] * 29 % md;
            hs[i] = (hs[i - 1] * 29 + (LL)s[i]) % md;
        }
    }
    void TEST() {
        int l, r, g;
        while EOF{
            scanf("%d %d %d",&l,&r,&g);
            printf("%lld %lld\n", (hs[r] - hs[l - 1] * pw[r - l + 1] % md + md) % md, ht[g]);
        }
    }
}
using namespace Hash;
LL g[N];
int main() {
    scanf(" %s %s", s + 1, t + 1);
    int S = strlen(s + 1), T = strlen(t + 1);
    Init(S, T);
    // TEST();
    for (int i = 2, j = 0;i <= T;i++) {
        while (j&&t[i] != t[j + 1])j = nx[j];
        if (t[i] == t[j + 1])++j;
        nx[i] = j;
    }
    for (int i = 2;i <= S;i++) {
        int l = 0, r = T + 1;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if (cmp(i, mid))l = mid;
            else r = mid;
        }
        g[l]++;
    }
    LL ans = (LL)T*S;
    for (int i = T ;i >= 1;i--) {
        g[i] += g[i + 1];
        // cout <<i<<' '<< g[i] << endl;
    }
    for (int i = 1;i <= T;i++) if(nx[i]){
        ans -= g[i - nx[i]];
        // cout <<i<<':'<< i - nx[i]<<' ';
    }
    printf("%lld\n", ans);
}