#include <bits/stdc++.h>
using namespace std;

string sort_it(string &s, int l, int r) {
    if ((r - l) % 2 == 1) {
        return s.substr(l, r - l);
    }

    string a = sort_it(s, l, (l + r) / 2);
    string b = sort_it(s, (l + r) / 2, r);

    if (a < b)
        return a + b;
    else 
        return b + a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s, t;
    cin >> s >> t;
    s = sort_it(s, 0, s.size());
    t = sort_it(t, 0, t.size());

    cout << (s == t ? "YES" : "NO") << endl;
    
    return 0;
}