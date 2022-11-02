#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, te, x, cnt[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        cin >> n;
        cnt[0] = cnt[1] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            cnt[x]++;
        }
        if (cnt[0] >= cnt[1]) {
            cout << n / 2 << '\n';
            for (int i = 1; i <= n / 2; i++) {
                cout << 0 << " \n"[i == n / 2];
            }
        } else {
            int cur = cnt[1] / 2 * 2;
            cout << cur << '\n';
            for (int i = 1; i <= cur; i++) {
                cout << 1 << " \n"[i == cur];
            }
        }
    }
}