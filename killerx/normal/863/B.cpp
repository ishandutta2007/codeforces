#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
    int n;
    scanf("%d", &n);
    vector <int> w(n * 2);
    rep(i, n * 2) scanf("%d", &w[i]);
    sort(w.begin(), w.end());
    int ans = 1e9 + 7;
    rep(i, n * 2) rep(j, i) {
        vector <int> nw;
        rep(k, n * 2) if (k != i && k != j) nw.pb(w[k]);
        int cur = 0;
        rep(k, nw.size() - 1) {
            cur += nw[k + 1] - nw[k];
            ++ k;
        }
        ans = min(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}