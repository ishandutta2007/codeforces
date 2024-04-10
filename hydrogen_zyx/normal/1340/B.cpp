#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok[2005][2005];
int dig[10] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
int a[3000];
int shu(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x -= x & -x;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 6; j >= 0; j--) {
            char c;
            cin >> c;
            if (c == '1') ans += 1 << j;
        }
        a[i] = ans;
    }
    ok[n + 1][0] = 1;
    for (int i = n + 1; i > 1; i--) {
        vector<int> v;
        for (int j = 0; j < 10; j++) {
            if ((dig[j] ^ a[i - 1]) == dig[j] - a[i - 1]) {
                v.push_back(shu(dig[j] - a[i - 1]));
            }
        }
        for (int x = 0; x <= k; x++) {
            if (!ok[i][x]) continue;
            for (auto y : v) {
                if (x + y <= 2000) ok[i - 1][x + y] = 1;
            }
        }
    }
    if (ok[1][k] == 0) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 9; j >= 0; j--) {
            if ((dig[j] ^ a[i]) != dig[j] - a[i]) continue;
            int cnt = shu(dig[j] ^ a[i]);
            if (k - cnt >= 0 && ok[i + 1][k - cnt]) {
                k -= cnt;
                cout << j;
                break;
            }
        }
    }
}