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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x--;
            b[x] = i;
        }
        int x = 0, y = 0;
        vector<int> used(n);
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue;
            }
            int j = i, c = 0;
            while (!used[j]) {
                used[j] = 1;
                c++;
                j = b[a[j]];
            }
            if (c % 2 == 0) {
                x += c / 2, y += c / 2;
            } else {
                x += c / 2, y += c / 2;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= y; i++) {
            ans -= 2 * i;
        }
        for (int i = n; i > n - x; i--) {
            ans += 2 * i;
        }
        cout << ans << '\n';
    }
}