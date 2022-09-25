#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        if (n == 1)
            cout << s << s << "\n";
        else if (s[0] == s[1])
            cout << s[0] << s[0] << "\n";
        else {
            int i = 0;
            while (i + 1 < n and s[i + 1] <= s[i]) i += 1;
            for (int j = 0; j <= i; j += 1) cout << s[j];
            for (int j = i; j >= 0; j -= 1) cout << s[j];
            cout << "\n";
        }
    }
    return 0;
}