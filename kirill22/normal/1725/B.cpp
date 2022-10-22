#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = n, ans = 0;
    for (int i = n - 1; i >= 0 && cnt; i--) {
        cnt--;
        int need = (d + a[i]) / a[i] - 1;
        if (cnt >= need) {
            cnt -= need;
            ans++;
        } else {
            break;
        }
    }
    cout << ans;
}