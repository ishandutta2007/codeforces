#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;
    for (int res = 1;; res++) {
        int cnt = a / res + b / res;
        if (cnt < n || res > a || res > b) {
            cout << res - 1 << '\n';
            return 0;
        }
    }
}