#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int q;
    for (cin >> q; q; q -= 1) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size(), ans = 0;
        for (int i = 0; i < n; i += 1) {
            for (int j = i; j < n; j += 1) {
                if (j - i + 1 + j >= m and j - i + 1 <= m) {
                    int ok = 1;
                    for (int k = 0; k < m; k += 1) {
                        if (k <= j - i) ok &= t[k] == s[i + k];
                        else ok &= t[k] == s[j - (k - (j - i))];
                    }
                    ans |= ok;
                }
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}