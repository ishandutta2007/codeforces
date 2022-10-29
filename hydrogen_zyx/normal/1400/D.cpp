#include <bits/stdc++.h>
using namespace std;
int a[5000];
int cnt[5000][5000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) cnt[i][j] = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        long long  ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans += cnt[a[i]][a[j]];
            }
            for (int j = 1; j < i; j++) {
                cnt[a[j]][a[i]]++;
            }
        }
        cout << ans << endl;
    }
}