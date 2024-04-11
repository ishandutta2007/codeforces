#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int p;
    int l = 0;
    p = 0;
    for (p = 0; p < (int) s.size() && l < (int) t.size(); l++) {
        if (s[p] == t[l]) p++;
    }
    if (p == s.size()) l--;

    int r = (int) t.size() - 1;
    for (p = (int) s.size() - 1; p >= 0 && r >= 0; r--) {
        if (s[p] == t[r]) p--;
    }
    if (p == -1) r++;

    cout << max(0, r - l) << endl;
}