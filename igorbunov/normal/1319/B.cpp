#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int kek[1000000];

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        kek[arr[i] - i + 300000] += arr[i];
    }
    int ans = 0LL;
    for (int i = 0; i < 1000000; i++) {
        ans = max(ans, kek[i]);
    }

    cout << ans;
    return 0;
}