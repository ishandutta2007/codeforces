#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> S(n);
        for (string &s : S) cin >> s;
        bool pos = false;
        set<string> sp;
        for (string i : S) {
            if (i.length() == 1) {
                pos = true;
                break;
            }
            else if (i.length() == 2) {
                string s = i;
                if (s[0] == s[1]) {
                    pos = true;
                    break;
                }
                reverse(s.begin(), s.end());
                auto it = sp.lower_bound(s);
                if (it != sp.end() && (*it)[0] == s[0] && (*it)[1] == s[1]) {
                    pos = true;
                    break;
                }
            }
            else if (i.length() == 3) {
                string s = i;
                if (s[0] == s[2]) {
                    pos = true;
                    break;
                }
                reverse(s.begin(), s.end());
                auto it = sp.find(s);
                if (it != sp.end()) {
                    pos = true;
                    break;
                }
                s.pop_back();
                it = sp.find(s);
                if (it != sp.end()) {
                    pos = true;
                    break;
                }
            }
            sp.insert(i);
        }
        printf(pos ? "YES\n" : "NO\n");
    }
    return 0;
}