#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        long long x;
        cin >> x;
        cout << (x >= 15 && 1 <= x % 14 && x % 14 <= 6 ? "YES" : "NO") << "\n";
    }
    return 0;
}