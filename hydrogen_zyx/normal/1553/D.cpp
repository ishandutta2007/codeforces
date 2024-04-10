#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int pos = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (pos == s2.length()) {
                break;
            }
            char c = s1[i];
            if (pos < s2.length() && c == s2[pos]) {
                pos++;
            } else {
                i++;
            }
        }
        if (pos == s2.length()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}