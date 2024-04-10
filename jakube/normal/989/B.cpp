#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    int idx = p-1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.' && i % p <= idx % p)
            idx = i;
    }

    for (int d = 0; d < 2; d++) {
        auto t = s;
        t[idx] = '0' + d;
        for (char& c : t) {
            if (c == '.')
                c = '0';
        }
        if (t.substr(0, n - p) != t.substr(p)) {
            cout << t << '\n';
            return 0;
        }
    }

    cout << "No" << '\n';
}