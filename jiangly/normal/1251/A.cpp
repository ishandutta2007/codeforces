#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    bool good[26] = {};
    for (int i = 0; i < s.length(); ) {
        int j = i;
        while (j < s.length() && s[i] == s[j])
            ++j;
        if ((j - i) % 2 == 1)
            good[s[i] - 'a'] = true;
        i = j;
    }
    string t;
    for (int i = 0; i < 26; ++i)
        if (good[i])
            t += 'a' + i;
    cout << t << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}