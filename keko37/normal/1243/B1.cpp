#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int tt, n;
string s, t;

int main () {
    cin >> tt;
    while (tt--) {
        cin >> n >> s >> t;
        int cnt = 0, lef, rig;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) cnt++;
        }
        for (int i = 0; i < n; i++) if (s[i] != t[i]) {lef = i; break;}
        for (int i = n-1; i >= 0; i--) if (s[i] != t[i]) {rig = i; break;}
        if (cnt == 2 && s[lef] == s[rig] && t[lef] == t[rig]) cout << "Yes\n"; else cout << "No\n";
    }
    return 0;
}