#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ans = 0;
        cin >> n;
        set<int> s = {0};
        for (int i = 0, ai, sum = 0; i < n; i += 1) {
            cin >> ai;
            if (ai == 0)
                s.clear();
            else {
                sum ^= ai;
                if (s.count(sum)) s.clear();
                else ans += 1;
            }
            s.insert(sum);
        }
        cout << ans << "\n";
    }
}