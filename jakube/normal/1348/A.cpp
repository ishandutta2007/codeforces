#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n;
        cin >> n;
        int a = 0;
        for (int i = n; i >= 1; i--) {
            if (i == n || i < n / 2) {
                a += 1 << i;
            } else {
                a -= 1 << i;
            }
        }
        cout << a << '\n';
    }
}