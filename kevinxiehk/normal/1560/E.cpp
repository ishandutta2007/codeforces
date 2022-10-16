#include<bits/stdc++.h>
using namespace std;
void solve() {
    string s, ord = ""; cin >> s;
    unordered_map<char, bool> yes;
    for(int i = s.length() - 1; i >= 0; i--) {
        if(!yes[s[i]]) ord = s[i] + ord;
        yes[s[i]] = true;
    }
    int cnt = 1, l = 0;
    for(auto c: ord) {
        int tc = 0;
        for(auto cc: s) tc += (c == cc);
        if(tc % cnt != 0) {
            cout << "-1\n";
            return;
        }
        l += tc / cnt;
        cnt++;
    }
    string ss = s.substr(0, l), sss = ss;
    for(auto c: ord) {
        ss.erase(remove(ss.begin(), ss.end(), c), ss.end());
        sss += ss;
    }
    if(sss != s) {
        cout << "-1\n";
    }
    else cout << s.substr(0, l) << ' ' << ord << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}