#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    string t, t2;
    for (char c : s) {
        t += c;
        if (c != 'a')
            t2 += c;
        if (t.size() + t2.size() == s.size() && t + t2 == s) {
            cout << t << endl;
            return 0;
        }
    }
    cout << ":(" << '\n';
}