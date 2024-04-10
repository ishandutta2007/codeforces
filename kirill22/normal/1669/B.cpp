#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x]++;
        }
        int res = -1;
        for (auto [x, cnt] : a) {
            if (cnt >= 3) {
                res = x;
            }
        }
        cout << res << '\n';
    }
}