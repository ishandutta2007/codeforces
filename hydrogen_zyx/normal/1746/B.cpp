#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int l = 1, r = n;
        int ans = 0;
        while (1) {
            while (l <= n && a[l] == 0) l++;
            while (r >= 1 && a[r] == 1) r--;
            if (l > r) break;
            swap(a[l], a[r]);
            ans++;
        }
        cout << ans << endl;
    }
}