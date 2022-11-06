#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

char vowel[256];

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = vowel['y'] = true;

    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    for (auto i: s) {
        if (ans.empty() || !vowel[ans.back()] || !vowel[i]) {
            ans.push_back(i);
        }
    }
    cout << ans << '\n';



}