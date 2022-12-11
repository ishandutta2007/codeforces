#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int inf = 1e9;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    if (sz(s) != sz(t)) {
        cout << "-1\n";
        return 0;
    }

    int k;
    cin >> k;

    vector<vector<int> > g(26, vector<int>(26, inf));
    for (int i = 0; i < 26; ++i) {
        g[i][i] = 0;
    }
    while (k--) {
        char a, b;
        int cost;
        cin >> a >> b >> cost;
        g[a - 'a'][b - 'a'] = min(g[a - 'a'][b - 'a'], cost);
    }
    for (k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int ans = 0;
    string p = "";
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == t[i]) {
            p += s[i];
            continue;
        }
        char r = '?';
        int relax = inf;
        for (int c = 0; c < 26; ++c) {
            if (g[s[i] - 'a'][c] + g[t[i] - 'a'][c] < relax) {
                relax = g[s[i] - 'a'][c] + g[t[i] - 'a'][c];
                r = (char)(c + 'a');
            }
        }
        if (relax == inf) {
            cout << "-1\n";
            return 0;
        }
        ans += relax;
        p += r;
    }

    cout << ans << "\n" << p << "\n";

}