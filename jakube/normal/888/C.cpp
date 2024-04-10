#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    map<char, int> last, mi;
    for (char c : s) {
        last[c] = -1;
        mi[c] = 1;
    }

    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        mi[c] = max(mi[c], i - last[c]);
        last[c] = i;
    }

    for (char c : s) {
        mi[c] = max(mi[c], (int)s.size() - last[c]);
    }

    int m = numeric_limits<int>::max();
    for (auto p : mi)
        m = min(m, p.second);
    cout << m << endl;
}