// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (auto& k : s) cin >> k;

        int sol = 0;
        for (char c : {'a', 'b', 'c', 'd', 'e'}) {
            vector<int> a(n);
            for (int i=0; i<n; i++) {
                int m = count(begin(s[i]), end(s[i]), c);
                m -= s[i].size() - m;
                a[i] = m;
            }
            sort(begin(a), end(a), greater<int>());

            int s = 0, z = 0, cnt = 0;
            for (int x : a) {
                s += x;
                cnt++;
                if (s > 0) {
                    z = max(z, cnt);
                }
            }

            sol = max(sol, z);
        }

        cout << sol << '\n';
    }
}