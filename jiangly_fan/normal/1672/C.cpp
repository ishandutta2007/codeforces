#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a)
            cin >> ai;
        int L = n, R = 0;
        for (int i = 1; i < n; i += 1)
            if (a[i] == a[i - 1]) {
                L = min(L, i);
                R = max(R, i);
            }
        if (L >= R) cout << "0\n";
        else if (L + 1 == R) cout << "1\n";
        else cout << R - L - 1 << "\n";
    }
    return 0;
}