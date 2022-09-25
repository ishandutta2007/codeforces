#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i += 1) {
            for (int j = 1; j <= n; j += 1) {
                if (j == i) cout << 1 << " ";
                else if (j < i) cout << n + 1 - j << " ";
                else cout << n + 1 - j + 1 << " ";
            }
            cout << "\n";
        }
    }
}