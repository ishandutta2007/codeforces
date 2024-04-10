#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    vector<bool> st(n);
    for (int i = 0; i < n; ++i)
        if (s[(i - 1 + n) % n] == s[i] || s[(i + 1) % n] == s[i]) {
            ++cnt;
            st[i] = true;
        }
    if (cnt == 0) {
        if (k % 2 == 1)
            for (char &c : s)
                c = c == 'B' ? 'W' : 'B';
        cout << s << "\n";
        return 0;
    }
    vector<int> l(n), r(n);
    int lst = n - 1;
    while (!st[lst]) --lst;
    for (int i = 0; i < n; ++i)
        if (st[i])
            lst = i;
        else
            l[i] = lst;
    lst = 0;
    while (!st[lst]) ++lst;
    for (int i = n - 1; i >= 0; --i)
        if (st[i])
            lst = i;
        else
            r[i] = lst;
    string t = s;
    for (int i = 0; i < n; ++i) {
        if (st[i]) continue;
        int ld = (i - l[i] + n) % n, rd = (r[i] - i + n) % n;
        if (ld > k && rd > k) {
            if (k % 2 == 1) t[i] = s[i] == 'B' ? 'W' : 'B';
        } else if (s[l[i]] == s[r[i]]) t[i] = s[l[i]];
        else t[i] = ld < rd ? s[l[i]] : s[r[i]]; 
    }
    cout << t << "\n";
    return 0;
}