#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int cnt[MAXN];
int arr[MAXN], lst[MAXN];

main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        cnt[arr[i]]++;
        lst[arr[i]]  = i;
    }
    int now = 0;
    int ans = 0;
    while (now != n) {
        int l = lst[arr[now]];
        int mx = 0;
        for (int i = now; i <= l; ++i) {
            mx = max(mx, cnt[arr[i]]);
            l = max(l, lst[arr[i]]);
        }
        ans += l - now + 1 - mx;
        now = l + 1;
        // cout << now << endl;
    }
    cout << ans;
    return 0;
}