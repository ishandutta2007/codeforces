#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    rep(cse, 0, n) {
        string s, t;
        cin >> s >> t;
        vi pos[26];
        for (int i = sz(s)-1; i >= 0; i--) {
            pos[s[i]-'A'].pb(i);
        }

        bool ok = true;
        int seen[26];
        rep(i, 0, 26) seen[i] = 0;
        vi p;
        for (int i = sz(t)-1; i >= 0; i--) {
            int ind = t[i]-'A';
            int occ = seen[ind];
            if (occ >= sz(pos[ind])) {
                ok = false;
                break;
            }
            p.pb(pos[ind][occ]);

            seen[ind]++;
        }

        vi pp = p;
        sort(all(pp));
        reverse(all(pp));
        if (pp != p) ok = false;
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}