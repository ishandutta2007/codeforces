#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 500005;

int n, sol = 1e9;
int a[MAXN], lef[MAXN], rig[MAXN], cnt[MAXN], dp[MAXN];
vector <pi> v[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        lef[i] = 1e9; rig[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        lef[a[i]] = min(lef[a[i]], i);
        rig[a[i]] = max(rig[a[i]], i);
    }
    for (int i = 1; i <= n; i++) {
        if (rig[i] != -1) {
            v[rig[i]].push_back({lef[i], cnt[i]});
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (auto pp : v[i]) {
            int pos = pp.first, br = pp.second;
            dp[i] = max(dp[i], dp[pos - 1] + br);
        }
    }
    for (int i = 1; i <= n; i++) {
        sol = min(sol, n - cnt[a[i]] - dp[i - 1]);
        cnt[a[i]]--;
    }
    cout << sol;
    return 0;
}