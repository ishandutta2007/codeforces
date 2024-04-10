#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 5005;

int n, a, b;
int val[MAXN];
int lef[20], rig[20], cnt[20];
int can[1 << 20], mn_ind[1 << 20], dp[1 << 20], ok[1 << 20];
string s, t, sol;

void sazmi () {
    t = s;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (int i = 0; i < n; i++) {
        val[i] = lower_bound(t.begin(), t.end(), s[i]) - t.begin();
    }
    for (int i = 0; i < n; i++) rig[val[i]] = i, cnt[val[i]]++;
    for (int i = n-1; i >= 0; i--) lef[val[i]] = i;
    n = t.size();
}

void precompute () {
    for (int mask = 1; mask < (1 << n); mask++) {
        int mn = 1e9, mx = -1e9, sum = 0, ind = -1;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += cnt[i];
                mx = max(mx, rig[i]);
                if (lef[i] < mn) {
                    mn = lef[i];
                    ind = i;
                }
            }
        }
        mn_ind[mask] = ind;
        can[mask] = a * (mx - mn + 1) <= b * sum;
    }
}

void calc () {
    ok[0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (can[mask]) {
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) && ok[mask ^ (1 << i)]) {
                    dp[mask] = 1;
                    break;
                }
            }
        }
        if (dp[mask]) {
            ok[mask] = 1;
            continue;
        }
        int novi = 0, ost = mask, lim = -1e9;
        while (1) {
            lim = max(lim, rig[mn_ind[ost]]);
            novi ^= 1 << mn_ind[ost];
            ost ^= 1 << mn_ind[ost];
            if (ost == 0) break;
            if (lim < lef[mn_ind[ost]] && dp[novi] && ok[ost]) {
                ok[mask] = 1;
                break;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> s;
    sazmi();
    precompute();
    calc();
    for (int i = 0; i < n; i++) {
        if (ok[((1 << n) - 1) ^ (1 << i)]) sol += t[i];
    }
    cout << sol.size() << " ";
    for (auto c : sol) cout << c << " ";
    return 0;
}