#include "bits/stdc++.h"
using namespace std;

void solve() {
    string s;
    cin >> s;
    long long res = 0;
    int diff = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+')
            diff++;
        else
            diff--;
        if (diff < 0) {
            res += i + 1;
            diff++;
        }
    }
    res += s.size();
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}