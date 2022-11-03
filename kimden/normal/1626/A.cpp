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
        string s;
        cin >> s;
        vector<int> cnt(444, 0);
        for (char c: s) {
            ++cnt[c];
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c] == 2) {
                cout << c;
            }
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c] == 1) {
                cout << c;
            }
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c] == 2) {
                cout << c;
            }
        }
        cout << "\n";
    }
}