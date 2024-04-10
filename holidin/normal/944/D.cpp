#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
const int N = 10000;

int m[26][26 * N];
int c[26];
int main() {
    int i, j, i1, n;
    string s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    for (i = 0; i < s.size(); ++i)
        s[i] -= 'a';
    for (i = 0; i < n; ++i) {
        char c1 = s[0];
        for (j = 0; j < s.size() - 1; ++j)
            s[j] = s[j + 1];
        s[s.size() - 1] = c1;
        for (j = 0; j < s.size(); ++j)
           ++m[s[0]][j * 27 + s[j]];
        ++c[s[0]];
    }
    long double sumv = 0;
    for (i = 0; i < 26; ++i) {
        long double maxv = 0;
        for (j = 0; j < n; ++j) {
            long double v = 0;
            for (i1 = 0; i1 < 26; ++i1)
            if (m[i][j * 27 + i1] == 1)
                v += 1.0 / c[i];
            maxv = max(maxv, v);
        }
        sumv += maxv * (c[i] * 1.0) / n;
    }
    cout << fixed << setprecision(10) << sumv;
}