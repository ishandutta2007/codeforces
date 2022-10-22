#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 205;

int n;
bool have[mxn][mxn];
int sz[mxn];
int cnt[mxn];
int a[mxn];
std::set <int> st[mxn];
int pos[mxn];

void Main() {
    scanf("%d", &n);
    rep(i, n - 1) {
        int k;
        scanf("%d", &k);
        sz[i] = k;
        rep(j, n) have[i][j] = false;
        rep(j, k) {
            int u;
            scanf("%d", &u);
            -- u;
            have[i][u] = true;
        }
    }
    for (a[0] = 0; a[0] < n; ++ a[0]) {
        rep(i, n - 1) {
            cnt[i] = 0;
            st[i].clear();
            rep(j, n) if (have[i][j]) {
                ++ cnt[i];
                st[i].insert(j);
            }
        }
        bool ok = true;
        for (int i = 1; i < n; ++ i) {
            pos[a[i - 1]] = i - 1;
            rep(j, n - 1) if (have[j][a[i - 1]]) {
                st[j].erase(a[i - 1]);
                -- cnt[j];
            }
            bool found = false;
            int fj;
            rep(j, n - 1) if (cnt[j] == 1) {
                if (found) {
                    ok = false;
                    break;
                }
                fj = j;
                found = true;
                a[i] = *st[j].begin();
            }
            if (!found) {
                ok = false;
                break;
            }
            if (!ok) break;
            int minpos = i;
            rep(j, n) if (have[fj][j] && j != a[i]) {
                minpos = std::min(minpos, pos[j]);
            }
            if (i - minpos + 1 != sz[fj]) {
                ok = false;
                break;
            }
        }
        if (ok) break;
    }
    rep(i, n) printf("%d ", a[i] + 1);
    printf("\n");
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}