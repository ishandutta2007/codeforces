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
        int tmp = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < 2; j++, x++) {
                if (x > tmp) {
                    ans++, tmp = x;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}