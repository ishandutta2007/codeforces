#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> last_pos(300300, -1);
        const int INF = n + 80;
        int min_diff = INF;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (last_pos[x] != -1) {
                min_diff = min(min_diff, i - last_pos[x]);
            }
            last_pos[x] = i;
        }
        if (min_diff == INF) {
            cout << -1 << "\n";
            continue;
        }
        cout << n - min_diff << "\n";
    }
}