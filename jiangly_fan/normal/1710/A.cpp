#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(k);
        for (int& ai : a)
            cin >> ai;
        sort(a.begin(), a.end());
        auto check = [&](int n, int m) {
            LL sum = 0;
            for (int ai : a)
                if (ai / n >= 2)
                    sum += ai / n;
            if (sum < m) return false;
            int x = a.back() / n;
            if (x == 2) return m % 2 == 0;
            return sum >= m;
        };
        cout << (check(n, m) or check(m, n) ? "Yes\n" : "No\n");
    }
    return 0;
}