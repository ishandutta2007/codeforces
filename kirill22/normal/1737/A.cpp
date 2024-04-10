#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    map<char, int> a;
    for (auto c : s) {
        a[c]++;
    }
    for (int i = 0; i < k; i++) {
        char c = 'a';
        int cnt = n / k;
        while (a[c] > 0 && cnt) {
            a[c]--;
            cnt--;
            c++;
        }
        cout << c;
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