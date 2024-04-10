#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;

map <int, int> m0, m1;
int a[N];

int main() {
    string s;
    int i, j, n, k, b, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    bool flag = false;
    for (i = 0; i < s.size() - 1; ++i)
    if (s[i] != s[i + 1])
        flag = 1;
    if (!flag) {
        cout << "Impossible";
        return 0;
    }
    if (s.size() % 2 == 1) {
        flag = false;
        for (i = 0; i < s.size() / 2 - 1; ++i)
        if (s[i] != s[i + 1])
            flag = true;
        if (!flag) {
            cout << "Impossible";
            return 0;
        }
    }
    for (i = 1; i <= s.size() / 2; ++i) {
        string t;
        for (j = i; j < s.size(); ++j)
            t += s[j];
        for (j = 0; j < i; ++j)
            t += s[j];
        flag = true;
        for (j = 0; j < t.size() / 2; ++j)
        if (t[j] != t[t.size() - j - 1])
            flag = false;
        if (flag && s != t) {
            cout << 1;
            return 0;
        }
    }
    cout << 2;
}