#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int tt, n;
string s, t;

int main () {
    cin >> tt;
    while (tt--) {
        cin >> n >> s >> t;
        bool ok = 1;
        vector < pair <int, int> > v;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            bool naso = 0;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    v.push_back({j, i});
                    swap(s[j], t[i]);
                    naso = 1; break;
                } else if (s[i] == t[j]) {
                    v.push_back({j, j}); v.push_back({j, i});
                    swap(s[j], t[j]); swap(s[j], t[i]);
                    naso = 1; break;
                }
            }
            if (!naso) {
                ok = 0;
                break;
            }
        }
        if (!ok) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            cout << v.size() << endl;
            for (auto par : v) {
                cout << par.first + 1 << " " << par.second + 1 << '\n';
            }
        }
    }
    return 0;
}