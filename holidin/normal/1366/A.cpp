#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 12;
const int inf = 2e9;
const int mod = 1e9 + 7;


void run() {
    int a, b;
    cin >> a >> b;
    if (2 * a <= b) {
        cout << a << endl;
        return;
    }
    if (2 * b <= a) {
        cout << b << endl;
        return;
    }
    cout << (a + b) / 3 << endl;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--)
        run();
}