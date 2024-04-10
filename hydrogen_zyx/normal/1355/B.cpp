#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int cnt = 0;
        int num = 0;
        for (int i = 0; i < n; i++) {
            num++;
            if (num >= a[i]) {
                cnt++;
                num = 0;
            }
        }
        cout << cnt << endl;
    }
}