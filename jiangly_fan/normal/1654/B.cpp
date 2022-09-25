#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a'] += 1;
        for (int i = 0; i < s.size(); i += 1) {
            cnt[s[i] - 'a'] -= 1;
            if (not cnt[s[i] - 'a']) {
                cout << s.substr(i) << "\n";
                break;
            }
        }
    }
    return 0;
}