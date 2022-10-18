#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    string t;
    auto it = s.begin();
    while (it != s.end()) {
        // find first
        char a = *it;
        ++it;
        while (it != s.end() && *it == a)
            ++it;
        if (it != s.end()) {
            char b = *it;
            ++it;
            t += a;
            t += b;
        }
    }
    cout << s.size() - t.size() << '\n';
    cout << t << endl;
}