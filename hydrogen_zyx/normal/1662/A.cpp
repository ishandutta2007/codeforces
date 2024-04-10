#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

vector<int> v[15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= 10; i++) v[i].clear();
        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            v[b].push_back(a);
        }
        for (int i = 1; i <= 10; i++) sort(v[i].rbegin(), v[i].rend());
        int ans = 0;
        bool ok = 1;
        for (int i = 1; i <= 10; i++) {
            if (v[i].empty()) {
                ok = 0;
                break;
            }
            ans += v[i][0];
        }
        if (ok) cout << ans << endl;
        else cout << "MOREPROBLEMS" << endl;
    }
}