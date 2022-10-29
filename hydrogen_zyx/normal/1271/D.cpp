#include <bits/stdc++.h>
using namespace std;
int least[10000];
int a[10000], b[10000], c[10000];
int g[10000];
pair<int, int> kk[10000];
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first || a.first == b.first && a.second > b.second;
}
int main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i <= n; i++) g[i] = i;
    for (int i = 1; i <= m; i++) {
        int aa, bb;
        cin >> aa >> bb;
        g[bb] = max(g[bb], aa);
    }
    least[n] = a[n];
    for (int i = n - 1; i > 0; i--) {
        least[i] = max(least[i + 1] - b[i], a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (k < a[i]) {
            cout << -1;
            return 0;
        }
        k += b[i];
        least[i] = k - least[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        kk[i] = pair<int, int>(c[i], g[i]);
    }
    // for (int i = 1; i <= n; i++) cout << least[i] << ' ';
    // cout << endl;
    sort(kk + 1, kk + 1 + n, cmp);
    /*for (int i = 1; i <= n; i++) {
        cout << kk[i].first << ' ' << kk[i].second << endl;
    }*/
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        bool f = 1;
        for (int j = kk[i].second; j <= n; j++) {
            if (least[j] == 0) f = 0;
        }
        if (f) {
            ans += kk[i].first;
            for (int j = kk[i].second; j <= n; j++) {
                least[j]--;
            }
        }
    }
    cout << ans;
}