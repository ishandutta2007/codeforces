#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        vector <pair <int, int> > op;
        rep(i, n) {
            int t, x;
            scanf("%d %d", &t, &x);
            op.pb(mp(t, x));
        }
        ll x = 0;
        int ans = 0;
        for (int i = 0; i < n; ) {
            ll k = x > op[i].second ? -1 : +1;
            ll b = x - k * op[i].first;
            int j;
            if (i + 1 == n || op[i].first + abs(x - op[i].second) <= op[i + 1].first) ++ ans;
            for (j = i + 1; j < n && op[j].first < op[i].first + abs(x - op[i].second); ++ j) {
                ll tme = (b - op[j].second) / (-k);
                if (tme >= op[j].first && tme <= op[i].first + abs(x - op[i].second) && (j + 1 == n || tme <= op[j + 1].first)) ++ ans;
            }
            x = op[i].second;
            i = j;
        }
        printf("%d\n", ans);
    }
    return 0;
}