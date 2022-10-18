#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    sort(s.begin(), s.end());
    vector<string> v(k);
    vector<int> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'a']++;
    }

    // fill first row
    for (int i = 0; i < k; i++) {
        v[i] += s[i];
        cnt[s[i] - 'a']--;
    }
    if (v.front() != v.back()) {
        cout << v.back() << '\n';
        return;
    }

    // all equal, continue
    // find first valid
    for (char c = 'a'; c <= 'z'; c++) {
        if (cnt[c - 'a']) {
            if (cnt[c - 'a'] + k == n) {
                for (int i = 0; i < n - k; i++) {
                    v[i%k] += c;
                }
                cout << v[0] << '\n';
                return;
            } else {
                cout << v[0] + s.substr(k) << '\n';
                return;
            }
        }
    }
    cout << v[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
    }
}