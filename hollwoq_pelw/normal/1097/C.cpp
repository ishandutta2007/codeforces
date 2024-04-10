#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int INF = 1000 * 1000;

int rd() {
    string s;
    cin >> s;

    int b = 0;
    bool bad = false;

    for (char c: s) {
        b += (c == '(') - (c == ')');
        bad |= b < 0;
    }

    if (!bad) {
        return b;
    }

    bad = false;
    b = 0;
    reverse(s.begin(), s.end());

    for (char c : s) {
        b += (c == '(') - (c == ')');
        bad |= b > 0;
    }

    if (!bad) {
        return b;
    }

    return INF;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    multiset<int> s;

    for (int i = 0; i < n; ++i) {
        int x = rd();
        auto it = s.find(-x);
        if (it == s.end()) {
            s.insert(x);
        } else {
            s.erase(it);
        }
    }

    cout << (n - s.size()) / 2 << "\n";
}