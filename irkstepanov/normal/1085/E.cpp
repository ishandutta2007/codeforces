#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int k;
        cin >> k;

        string s, a, b;
        cin >> s >> a >> b;
        int n = sz(s);

        vector<int> x;
        vector<int> p(k, -1);
        bool goodx = true;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (p[c] != -1) {
                if (p[c] < a[i] - 'a') {
                    goodx = false;
                    break;
                } else if (p[c] == a[i] - 'a') {
                    continue;
                } else {
                    goodx = true;
                    break;
                }
            }
            p[c] = a[i] - 'a';
            x.pb(i);
        }

        bool found = false;

        for (int u = 0; u <= sz(x); ++u) {
            if (u == sz(x) && !goodx) {
                continue;
            }
            p.assign(k, -1);
            vector<bool> occ(k, false);
            bool ok = true;
            for (int i = 0; i < u; ++i) {
                if (occ[a[x[i]] - 'a']) {
                    ok = false;
                    break;
                }
                occ[a[x[i]] - 'a'] = true;
                p[s[x[i]] - 'a'] = a[x[i]] - 'a';
            }
            if (u < sz(x)) {
                int pos = a[x[u]] - 'a' + 1;
                while (pos < k && occ[pos]) {
                    ++pos;
                }
                if (pos == k) {
                    ok = false;
                } else {
                    p[s[x[u]] - 'a'] = pos;
                    occ[pos] = true;
                }
            }

            if (!ok) {
                continue;
            }
            int pos = 0;
            for (int i = 0; i < n; ++i) {
                if (p[s[i] - 'a'] != -1) {
                    continue;
                }
                while (occ[pos]) {
                    ++pos;
                }
                p[s[i] - 'a'] = pos;
                occ[pos] = true;
            }

            string res = "";
            for (int i = 0; i < n; ++i) {
                res += char(p[s[i] - 'a'] + 'a');
            }
            if (res > b) {
                continue;
            }

            found = true;
            cout << "YES\n";
            for (int i = 0; i < k; ++i) {
                if (p[i] != -1) {
                    continue;
                }
                while (occ[pos]) {
                    ++pos;
                }
                p[i] = pos;
                occ[pos] = true;
            }
            for (int i = 0; i < k; ++i) {
                cout << char(p[i] + 'a');
            }
            cout << "\n";
            break;
        }

        if (!found) {
            cout << "NO\n";
        }
    }

}