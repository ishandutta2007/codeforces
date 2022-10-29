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
        int n, m;
        cin >> n >> m;
        int maxa = 0, maxb = 0;
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            maxa = max(maxa, a);
            maxb = max(maxb, b);
        }
        if (maxa + maxb <= n) {
            while (maxa--) n--, cout << 'R';
            while (maxb--) n--, cout << 'W';
            while (n--) cout << 'W';
            cout << endl;
        } else {

            cout << "IMPOSSIBLE" << endl;
        }
    }
}