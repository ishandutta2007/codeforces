#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[311111];
int main() {
    int n;
    scanf("%d", &n);
    map<int,int> vals;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int lf = 0, rg = 0, mn = 0;
        for (char *c = s; *c; c++) {
            rg += *c == '(' ? 1 : -1;
            mn = min(mn, rg);
        }
        lf -= mn, rg -= mn;
        if (!(lf && rg)) {
            vals[rg - lf]++;
        }
    }
    ll ans = 0;
    for (auto it: vals) {
        if (it.first >= 0) {
            ans += it.second * ll(vals[-it.first]);
        }
    }
    printf("%lld\n", ans);
}