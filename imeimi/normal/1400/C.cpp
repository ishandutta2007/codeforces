#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

string nxt(string s) {
    int n = s.length();
    string r(n, '0');
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (i) r[i - 1] = '1';
            if (i + 1 < n) r[i + 1] = '1';
        }
    }
    return r;
}

string solve(string s) {
    int n = s.length();
    string r(n, '1');
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (i) r[i - 1] = '0';
            if (i + 1 < n) r[i + 1] = '0';
        }
    }
    if (nxt(r) == s) return r;
    return string();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        string s; int x;
        cin >> s >> x;
        vector<string> S(x);
        for (int i = 0; i < int(s.length()); ++i) {
            S[i % x].push_back(s[i]);
        }
        bool pos = 1;
        for (int i = 0; i < x; ++i) {
            S[i] = solve(S[i]);
            if (S[i].empty()) {
                pos = 0;
                break;
            }
        }
        if (!pos) printf("-1");
        else for (int i = 0; i < int(s.length()); ++i) printf("%c", S[i % x][i / x]);
        printf("\n");
    }
    return 0;
}