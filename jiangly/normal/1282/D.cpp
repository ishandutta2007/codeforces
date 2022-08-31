#include <bits/stdc++.h>
using namespace std;
int query(const string &s) {
    cout << s << endl;
    int ans;
    cin >> ans;
    if (ans == 0)
        exit(0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a(300, 'a'), b(300, 'b');
    int ja = query(a), jb = query(b);
    int ca = 300 - ja, cb = 300 - jb;
    int len = ca + cb;
    string s(len, 'a'), t = s;
    int x = cb;
    for (int i = 0; i < len - 1; ++i) {
        s[i] = 'b';
        if (query(s) < cb) {
            t[i] = 'b';
            --x;
        }
        s[i] = 'a';
    }
    if (x == 1)
        t[len - 1] = 'b';
    cout << t << endl;
    return 0;
}