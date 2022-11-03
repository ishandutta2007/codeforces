#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const char NONE = 'A';

struct matching {
    vector<char> to;
    vector<char> from;

    matching(): to(256, NONE), from(256, NONE) {}

    bool try_assign(char left, char right) {
        if (to[left] != NONE || from[right] != NONE) {
            if (to[left] == right)
                return true;
            return false;
        }
        to[left] = right;
        from[right] = left;
        return true;
    }
};

void solve() {
    int k;
    cin >> k;
    string s, a, b;
    cin >> s >> a >> b;
    matching m;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            if (!m.try_assign(s[i], a[i])) {
                cout << "NO\n";
                return;
            }
        } else {
            bool found = false;
            for (char c = min(a[i], b[i]) + 1; c < max(a[i], b[i]); ++c) {
                if (m.try_assign(s[i], c)) {
                    found = true;
                    break;
                }
            }
            matching m1 = m;
            matching m2 = m;
            if (!found && m1.try_assign(s[i], a[i])) {
                char ptr = 'a' + k - 1;
                bool still_equal = true;
                bool bad = false;
                for (int j = i + 1; j < n; ++j) {
                    if (m1.to[s[j]] == NONE) {
                        while (ptr >= 'a' && m1.from[ptr] != NONE) {
                            --ptr;
                        }
                        m1.try_assign(s[j], ptr);
                    }
                    char c = m1.to[s[j]];
                    if (still_equal && c > a[j]) {
                        still_equal = false;
                    }
                    if (still_equal && c < a[j]) {
                        bad = true;
                        break;
                    }
                }
                if (!bad) {
                    m = m1;
                    found = true;
                }
            }
            if (!found && m2.try_assign(s[i], b[i])) {
                char ptr = 'a';
                bool still_equal = true;
                bool bad = false;
                for (int j = i + 1; j < n; ++j) {
                    if (m2.to[s[j]] == NONE) {
                        while (ptr <= 'a' + k - 1 && m2.from[ptr] != NONE) {
                            ++ptr;
                        }
                        m2.try_assign(s[j], ptr);
                    }
                    char c = m2.to[s[j]];
                    if (still_equal && c < b[j]) {
                        still_equal = false;
                    }
                    if (still_equal && c > b[j]) {
                        bad = true;
                        break;
                    }
                }
                if (!bad) {
                    m = m2;
                    found = true;
                }
            }
            if (!found) {
                cout << "NO\n";
                return;
            }
            break;
        }
    }
    char i = 'a';
    char j = 'a';
    while (i < 'a' + k) {
        while (i < 'a' + k && m.to[i] != NONE) {
            ++i;
        }
        while (j < 'a' + k && m.from[j] != NONE) {
            ++j;
        }
        assert(m.try_assign(i, j));
    }
    cout << "YES\n";
    for (char c = 'a'; c < 'a' + k; ++c) {
        cout << m.to[c];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}