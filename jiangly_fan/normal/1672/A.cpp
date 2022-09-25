#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        int s = 0;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            s += a - 1;
        }
        cout << (s & 1 ? "errorgorn\n" : "maomao90\n");
    }
    return 0;
}