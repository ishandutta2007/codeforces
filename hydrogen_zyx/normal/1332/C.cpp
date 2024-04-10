#include <bits/stdc++.h>
using namespace std;
char c[200000];
int cnt[300];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = n;

        cin >> c + 1;
        for (int i = 1; i <= (k + 1) / 2; i++) {
            int mmax = 0;
            if (k - i + 1 != i) {
                memset(cnt, 0, sizeof(cnt));
                for (int j = 0; j < n; j += k) {
                    cnt[c[j + i]]++;
                    cnt[c[j + k - i + 1]]++;
                    mmax = max(cnt[c[j + i]], mmax);
                    mmax = max(cnt[c[j + k - i + 1]], mmax);
                }
                ans -= mmax;
            } else {
                memset(cnt, 0, sizeof(cnt));
                for (int j = 0; j < n; j += k) {
                    cnt[c[j + i]]++;
                    mmax = max(mmax, cnt[c[j + i]]);
                }
                ans -= mmax;
            }
        }
        cout << ans << endl;
    }
}