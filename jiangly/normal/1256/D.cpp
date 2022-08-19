#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void solve() {
    int n;
    LL k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            pos.push_back(i);
            s[i] = '1';
        }
    }
    for (int i = 0; i < (int)pos.size(); ++i) {
        if (pos[i] - i > k) {
            pos[i] -= k;
            break;
        }
        k -= pos[i] - i;
        pos[i] = i;
    }
    for (int i : pos)
        s[i] = '0';
    cout << s << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}