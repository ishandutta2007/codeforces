#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
llint cnt[35];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            for (int j = 30; j >= 0; j--) {
                if (x & (1 << j)) {
                    cnt[j]++;
                    break;
                }
            }
        }
        llint sol = 0;
        for (int i = 0; i <= 30; i++) {
            sol += cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << sol << '\n';
    }
    return 0;
}