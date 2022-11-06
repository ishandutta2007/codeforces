#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) cnt--;
        if (a > b) cnt++;
    }

    if (cnt < 0) cout << "Chris";
    if (cnt == 0) cout << "Friendship is magic!^^";
    if (cnt > 0) cout << "Mishka";
}