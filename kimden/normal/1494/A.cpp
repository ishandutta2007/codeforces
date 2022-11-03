#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        string b = a;
        bool ans = false;
        for (int i = 0; i < 8 && !ans; ++i) {
            int level = 0;
            for (int j = 0; j < a.length(); ++j) {
                int add = ((i >> (a[j] - 'A')) & 1) * 2 - 1;
                level += add;
                if (level < 0) {
                    break;
                }
            }
            if (level == 0) {
                ans = true;
            }
        }
        cout << (ans ? "yes" : "no") << "\n";
    }



}