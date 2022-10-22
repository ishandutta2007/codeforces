#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string res = "";
    while ((int) s.size()) {
        if (s.back() == '0') {
            s.pop_back();
            res.push_back((char) ('a' + (s.back() - '0') + (s.end()[-2] - '0') * 10 - 1));
            s.pop_back();
            s.pop_back();
        } else {
            res.push_back((char) ('a' + (s.back() - '0') - 1));
            s.pop_back();
        }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}