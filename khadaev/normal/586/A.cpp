#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans, cnt = 2;
    cin >> n;
    ans = n + 2;
    int now;
    for (int i = 0; i < n; ++i) {
        cin >> now;
        if (now == 0) ++cnt;
        else {
            if (cnt >= 2) ans -= cnt;
            cnt = 0;
        }
    }
    ans -= cnt;
    cout << ans << endl;
}