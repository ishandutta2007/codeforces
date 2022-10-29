#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        int i = 0;
        for (i = n; i > 0; i--) {
            if (a[i] > i)
                continue;
            else {
                break;
            }
        }
        cout << i + 1 << endl;
    }
}