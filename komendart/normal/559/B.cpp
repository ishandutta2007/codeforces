#include <bits/stdc++.h>

using namespace std;

void sort1(string &s, int l, int r) {
    if ((r - l) & 1) return;
    int m = (l + r) / 2;
    sort1(s, l, m);
    sort1(s, m, r);
    bool cond = false;
    for (int i = 0; i < m - l; i++) {
        if (s[l + i] != s[m + i]) {
            cond = (s[l + i] > s[m + i]);
            break;
        }
    }
    if (cond) {
        for (int i = 0; i < m - l; i++) {
            swap(s[l + i], s[m + i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    sort1(s, 0, s.size());
    sort1(t, 0, t.size());

    if (s == t) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}