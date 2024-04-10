#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int h, m;
        cin >> h >> m;
        cout << 1440 - 60 * h - m << "\n";
    }
    return 0;
}