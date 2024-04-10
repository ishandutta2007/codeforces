#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        if (ranges::max(a) == 0) cout << "0\n";
        else {
            vector<int> p;
            for (int i = 0; i < n; i += 1)
                if (a[i]) p.push_back(i);
            int ok = 1;
            for (int i = 0; i + 1 < p.size(); i += 1)
                if (p[i] + 1 != p[i + 1]) ok = 0;
            cout << 2 - ok << "\n";
        }
    }
    return 0;
}