#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        vector<int> a(2);
        string s; cin >> s;
        for (int i = 0; i < s.size(); i++) {
            (a[i % 2] *= 10) += s[i] - '0';
        }
        cout << 1LL * (a[0] + 1) * (a[1] + 1) - 2 << '\n';
    }
}