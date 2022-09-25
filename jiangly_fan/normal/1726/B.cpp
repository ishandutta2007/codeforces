#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        if (n > m) cout << "No\n";
        else if (n & 1) {
            cout << "Yes\n";
            for (int i = 0; i < n - 1; i += 1) cout << "1 ";
            cout << m - n + 1 << "\n";
        }
        else if ((m - n) & 1) cout << "No\n";
        else {
            cout << "Yes\n";
            for (int i = 0; i < n - 2; i += 1) cout << "1 ";
            cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << "\n";
        }
    }
}