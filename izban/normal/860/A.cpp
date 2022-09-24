#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 18;
const int MOD = (int)1e9 + 7;

bool isBad(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    string s;
    while (cin >> s) {
        int n = s.length();

        int fr = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (i - fr >= 2 && isBad(s[i]) && isBad(s[i - 1]) && isBad(s[i - 2]) && (s[i] != s[i - 1] || s[i] != s[i - 2])) {
                ans += ' ';
                fr = i;
            }
            ans += s[i];
        }
        cout << ans << endl;
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}