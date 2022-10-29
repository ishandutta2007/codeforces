#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool ok = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) ok = 1;
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}