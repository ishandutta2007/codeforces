#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    string s; cin >> s;
    int n = s.size();
    bool different = false;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[0]) {
            different = true;
            break;
        }
    }
    if (!different) {
        puts("Impossible");
        return 0;
    }
    if ((n & 1) == 1) {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == s[n / 2]) ++cnt;

        bool same = true;
        for (int i = 1; i < n; ++i) {
            if (i != n / 2 && s[i] != s[0]) {
                same = false;
                break;
            }
        }

        if (cnt == 1 && same) {
            puts("Impossible");
            return 0;
        }
    }

    string w = s + s;
    for (int beg = 1; beg < n; ++beg) {
        bool palin = true, same = true;
        for (int i = 0; i < n; ++i) {
            if (w[i] != w[beg + i]) {
                same = false;
            }
            if (w[beg + i] != w[beg + n - i - 1]) {
                palin = false;
                break;
            }
        }
        if (palin && !same) {
            puts("1");
            return 0;
        }
    }
    puts("2");

    return 0;
}