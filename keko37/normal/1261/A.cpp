#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int tt, n, k;
string s, t;
vector < pair <int, int> > v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        cin >> n >> k >> s;
        t = "";
        v.clear();
        for (int i = 0; i < k - 1; i++) {
            t += "()";
        }
        for (int i = 0; i < n/2 - k + 1; i++) {
            t += "(";
        }
        for (int i = 0; i < n/2 - k + 1; i++) {
            t += ")";
        }
        for (int i = 0; i < n; i++) {
            int pos = i;
            for (int j = i; j < n; j++) {
                if (s[j] == t[i]) {
                    pos = j;
                    break;
                }
            }
            if (i < pos) {
                reverse(s.begin() + i, s.begin() + pos + 1);
                v.push_back({i + 1, pos + 1});
            }
        }
        cout << v.size() << '\n';
        for (auto x : v) cout << x.first << " " << x.second << '\n';
    }
    return 0;
}