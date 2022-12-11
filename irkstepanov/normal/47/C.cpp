#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool ok;
vector<string> s(6);

void f(int a, int b, int x, int y) {
    char c1, c2;
    if (x == 0) {
        c1 = s[a][0];
    } else {
        c1 = s[a][sz(s[a]) - 1];
    }
    if (y == 0) {
        c2 = s[b][0];
    } else {
        c2 = s[b][sz(s[b]) - 1];
    }
    if (c1 != c2) {
        ok = false;
    }
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 0; i < 6; ++i) {
        cin >> s[i];
    }

    vector<int> p(6);
    for (int i = 0; i < 6; ++i) {
        p[i] = i;
    }

    vector<string> ans;

    do {
        ok = true;
        f(p[0], p[1], 0, 0);
        f(p[0], p[2], 1, 0);
        f(p[1], p[3], 1, 0);
        f(p[2], p[4], 1, 0);
        f(p[3], p[5], 1, 0);
        f(p[4], p[5], 1, 1);
        if (sz(s[p[0]]) + sz(s[p[4]]) - 1 != sz(s[p[3]])) {
            ok = false;
        }
        if (sz(s[p[1]]) + sz(s[p[5]]) - 1 != sz(s[p[2]])) {
            ok = false;
        }
        if (!ok) {
            continue;
        }
        if (s[p[2]][sz(s[p[1]]) - 1] != s[p[3]][sz(s[p[0]]) - 1]) {
            continue;
        }
        vector<string> curr;
        int a = sz(s[p[2]]), b = sz(s[p[3]]);
        for (int i = 0; i < a; ++i) {
            string c = "";
            for (int j = 0; j < b; ++j) {
                c += ".";
            }
            curr.pb(c);
        }
        for (int i = 0; i < sz(s[p[0]]); ++i) {
            curr[0][i] = s[p[0]][i];
        }
        for (int i = 0; i < sz(s[p[1]]); ++i) {
            curr[i][0] = s[p[1]][i];
        }
        for (int i = 0; i < sz(s[p[2]]); ++i) {
            curr[i][sz(s[p[0]]) - 1] = s[p[2]][i];
        }
        for (int i = 0; i < sz(s[p[3]]); ++i) {
            curr[sz(s[p[1]]) - 1][i] = s[p[3]][i];
        }
        for (int i = 0; i < sz(s[p[4]]); ++i) {
            curr[a - 1][i + sz(s[p[0]]) - 1] = s[p[4]][i];
        }
        for (int i = 0; i < sz(s[p[5]]); ++i) {
            curr[i + sz(s[p[1]]) - 1][b - 1] = s[p[5]][i];
        }
        if (ans.empty() || ans > curr) {
            ans = curr;
        }
    } while (next_permutation(all(p)));

    if (ans.empty()) {
        cout << "Impossible\n";
        return 0;
    }
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i] << "\n";
    }

}