#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, v1 = 0;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) {
            cin >> ai;
            if (ai == 1) v1 = 1;
        }
        ranges::sort(a);
        if (not v1) cout << "YES\n";
        else {
            int ok = 1;
            for (int i = 1; i < n; i += 1)
                if (a[i] == a[i - 1] + 1)
                    ok = 0;
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
    return 0;
}