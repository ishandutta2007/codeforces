#include<bits/stdc++.h>

using namespace std;

const int mx = 100, add = 200000;

int dp[mx][add * 2 + 1];

int solve(vector<int> a) {
    int n = (int) a.size(), ans = 0, tmp = 0;
    vector<int> cnt(mx);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] > tmp) {
            st = {a[i]};
            tmp = cnt[a[i]];
        } else if (cnt[a[i]] == tmp) {
            st.insert(a[i]);
        }
        if ((int) st.size() >= 2) {
            ans = max(ans, i + 1);
        }
    }
    int x = *st.begin();
    fill(cnt.begin(), cnt.end(), 0);
    tmp = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] > tmp) {
            tmp = cnt[a[i]];
        }
        if (i + 1 > ans) {
            int r = i + 1;
            for (int y = 0; y < mx; y++) {
                if (y == x) {
                    continue;
                }
                int need = cnt[x] - cnt[y] + add;
                if (dp[y][need]) {
                    r = min(r, dp[y][need]);
                }
            }
            ans = max(ans, i - r + 1);
        }
        for (int y = 0; y < mx; y++) {
            if (x == y) {
                continue;
            }
            int have = cnt[x] - cnt[y] + add;
            if (!dp[y][have]) {
                dp[y][have] = i + 1;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    cout << solve(a);
}