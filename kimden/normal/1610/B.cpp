// HI
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> v;
        for (int i = 0; i < n - 1 - i; ++i) {
            if (a[i] != a[n - 1 - i]) {
                v.push_back(a[i]);
                v.push_back(a[n - 1 - i]);
                break;
            }
        }
        if (v.empty()) {
            cout << "YES\n";
            continue;
        }
        bool ok = false;
        for (int x: v) {
            vector<int> w;
            for (int y: a) {
                if (y != x) {
                    w.push_back(y);
                }
            }
            int s = w.size();
            bool hmm = true;
            for (int i = 0; i < s - 1 - i; ++i) {
                if (w[i] != w[s - 1 - i]) {
                    hmm = false;
                    break;
                }
            }
            if (hmm) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


}