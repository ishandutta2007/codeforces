#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = cos(-1.0);
const ll inf = 0x3f3f3f3f3f3f3f3f;
char a[N];
char b[N];
int cnt[N][4];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> a + 1;
        for (int i = 1; i <= n; i++) {
            b[i] = a[i];
            if (i & 1) {
                if (b[i] == 'L') b[i] = 'R';
                else b[i] = 'L';
            } else {
                if (a[i] == 'L') a[i] = 'R';
                else a[i] = 'L';
            }
        }
        cnt[0][0] = cnt[0][2] = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 'L') cnt[i][0] = cnt[i - 1][0] + 1;
            else cnt[i][0] = 1;
            if (b[i] == 'L') cnt[i][2] = cnt[i - 1][2] + 1;
            else cnt[i][2] = 1;
        }
        cnt[n][1] = cnt[n][3] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i + 1] == 'R') cnt[i][1] = cnt[i + 1][1] + 1;
            else cnt[i][1] = 1;
            if (b[i + 1] == 'R') cnt[i][3] = cnt[i + 1][3] + 1;
            else cnt[i][3] = 1;
        }
        for (int i = 0; i <= n; i++) {
            if (i & 1) cout << cnt[i][0] + cnt[i][3] - 1 << ' ';
            else cout << cnt[i][1] + cnt[i][2] - 1 << ' ';
        }
        cout << endl;
    }
}