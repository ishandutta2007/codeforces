// Hydro submission #615102e4476d3170ca34c4af@1632699108606
/**
 * File              : CF1567C.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/24/2021
 */
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
std::string s, s1, s2, s3;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        s1.clear(), s2.clear();
        cin >> s;
        for (unsigned i = 0; i < s.length(); ++i) {
            if (i & 1)
                s1 += s[i];
            else
                s2 += s[i];
        }
        if (s1.empty()) {
            cout << stoi(s2) - 1 << endl;
            continue;
        }
        cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2 << endl;
    }
    return 0;
}