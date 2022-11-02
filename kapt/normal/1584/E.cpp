#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 4e5, MAXLN = 19;
int arr[MAXN], pref[MAXN];
int sp[2][MAXLN][MAXN];
int lg[MAXN];
int cnt[MAXN];

int get(int i, int l, int r) {
    r++;
    int lvl = lg[r - l];
    return min(sp[i][lvl][l], sp[i][lvl][r - (1 << lvl)]);
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        pref[0] = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            pref[i + 1] = arr[i] - pref[i];
        }
        lg[1] = 0;
        for (int i = 2; i <= n + 10; ++i) {
            lg[i] = lg[i / 2] + 1;
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = i; j <= n; j += 2) {
                sp[i][0][j / 2] = pref[j];
            }
            for (int l = 1; l < MAXLN; ++l) {
                for (int j = 0; j + (1 << l) <= (n + 10) / 2; ++j) {
                    sp[i][l][j] = min(sp[i][l - 1][j], sp[i][l - 1][j + (1 << (l - 1))]);
                }
            }
        }
        fill(cnt, cnt + n + 1, 0);
        int ans = 0;
        for (int l = n - 1; l >= 0; --l) {
            int lft = l, rgh = n + 1;
            while (rgh - lft > 1) {
                int m = (lft + rgh) / 2;
                int m1 = m, m2 = m;
                if ((m - l) % 2 == 0) {
                    m1--;
                } else {
                    m2--;
                }
                int mn = 1e9;
                if (m1 >= l + 1) {
                    mn = min(mn, get((l + 1) % 2, (l + 1) / 2, m1 / 2) + pref[l]);
                }
                if (m2 >= l + 2) {
                    mn = min(mn, get((l + 2) % 2, (l + 2) / 2, m2 / 2) - pref[l]);
                }
                if (mn > 0) {
                    lft = m;
                } else {
                    rgh = m;
                }
            }
            if (rgh == n + 1) continue;
            int m = rgh;
            int m1 = m, m2 = m;
            if ((m - l) % 2 == 0) {
                m1--;
            } else {
                m2--;
            }
            int mn = 1e9;
            if (m1 >= l + 1) {
                mn = min(mn, get((l + 1) % 2, (l + 1) / 2, m1 / 2) + pref[l]);
            }
            if (m2 >= l + 2) {
                mn = min(mn, get((l + 2) % 2, (l + 2) / 2, m2 / 2) - pref[l]);
            }
            if (mn < 0) {
                continue;
            }
            cnt[l] = 1 + cnt[rgh];
            ans += cnt[l];
        }
        cout << ans << '\n';
    }
    return 0;
}