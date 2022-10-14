#include<bits/stdc++.h>

using namespace std;

const int MAXN = 85;
const int MAXM = 100005;
const int INF = 1000000007;

int n, m;
pair <int, int> p[MAXN];
int dp[MAXM], prosli[MAXM], mn[MAXM];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    for (int i = 0; i <= m; i++) {
        prosli[i] = INF;
    }
    prosli[m] = 0;
    for (int i = n-1; i >= 0; i--) {
        int pos = p[i].first, r = p[i].second;
        for (int j = m; j >= 0; j--) {
            mn[j] = prosli[j] + j;
            if (j < m) mn[j] = min(mn[j], mn[j + 1]);
        }
        for (int j = 0; j <= m; j++) {
            int cost = 0, rig = pos + r;
            if (j + 1 < pos - r) {
                cost += pos - r - j - 1;
                rig += cost;
            }
            rig = min(rig, m);
            dp[j] = prosli[j];
            dp[j] = min(dp[j], mn[rig] - rig + cost);
        }
        for (int j = 0; j <= m; j++) {
            prosli[j] = dp[j];
        }
    }
    cout << prosli[0];
    return 0;
}