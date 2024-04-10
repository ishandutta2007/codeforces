#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0, cnt = 0, prev = 0, tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp >= prev) ++cnt;
        ans = max(ans, cnt);
        if (tmp < prev) cnt = 1;
        prev = tmp;
        //cout << cnt << " ";
        };
    cout << ans;
};