#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int q;
    for (cin >> q; q; q -= 1) {
        string s, t;
        cin >> s >> t;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int j = 0, i = 0, ok = 1;
        while(i < s.size() and j < t.size()) {
            int si = i;
            while(i < s.size() and (s[i] != t[j] or ((i - si) & 1))) i += 1;
            if (i == s.size()) {
                ok = 0;
                break;
            }
            i += 1;
            j += 1;
        }
        ok &= j == t.size();
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}