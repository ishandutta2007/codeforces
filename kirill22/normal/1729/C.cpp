#include "bits/stdc++.h"

using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, vector<int>> pos;
    for (int i = 0; i < (int) s.size(); i++) {
        pos[s[i]].push_back(i);
    }
    char a = s[0], b = s.back();
    cout << abs(a - b) << " ";
    vector<int> ans;
    while (1) {
        for (auto i : pos[a]) {
            ans.push_back(i);
        }
        if (a < b) {
            a++;
        } else if (a > b) {
            a--;
        } else {
            break;
        }
    }
    cout << (int) ans.size() << '\n';
    for (auto i : ans) {
        cout << i + 1 << " ";
    }
    cout << '\n';
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