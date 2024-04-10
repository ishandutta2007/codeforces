#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k, ok = 0;
        cin >> n >> k;
        set<int> s;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            s.insert(a);
        }
        for (int ai : s) if (s.contains(ai + k)) ok = 1;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}