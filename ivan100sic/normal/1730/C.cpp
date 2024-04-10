// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        const int n = ssize(s);

        vector<int> pos;
        int base = 0;
        for (char c : ra('0', '9' + 1)) {
            for (int i : ra(base, n)) {
                if (s[i] == c) {
                    pos.push_back(i);
                    base = i;
                }
            }
        }

        vector<int> freq(10, 0);
        for (char c : s) freq[c-'0']++;
        for (int i : pos) freq[s[i]-'0']--;

        string f;
        for (int i : pos) f += s[i];

        string e;
        for (int i : ra(0, 10)) {
            e += string(freq[i], min<char>('9', '0' + i + 1));
        }

        string sol = s;
        R::merge(f, e, sol.begin());

        cout << sol << '\n';
    }
}