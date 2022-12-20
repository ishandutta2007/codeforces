#include <bits/stdc++.h>
using namespace std;

int i, j, n, k;
string s, t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s >> t;
    if (s == t) {
        cout << "YES";
        return 0;
    }
    int p = -1;
    for (i = 0; i < n; ++i)
    if (s[i] == '*')
        p = i;
    if (p == -1 || s.size() > t.size() + 1) {
        cout << "NO";
        return 0;
    }
    bool flag = true;
    for (i = 0; i < p; ++i)
    if (t.size() <= i || t[i] != s[i])
        flag = false;
    for (i = 1; s.size() - i > p; ++i)
    if (i > t.size() || s[s.size() - i] != t[t.size() - i])
        flag = false;
    if (flag)
        cout << "YES";
    else
        cout << "NO";
}