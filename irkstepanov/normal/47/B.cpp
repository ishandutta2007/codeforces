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

vector<vector<int> > g(3);

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; ++i) {
        string s;
        cin >> s;
        if (s[1] == '>') {
            g[s[0] - 'A'].pb(s[2] - 'A');
        } else {
            g[s[2] - 'A'].pb(s[0] - 'A');
        }
    }

    if (!g[0].empty() && !g[1].empty() && !g[2].empty()) {
        cout << "Impossible\n";
        return 0;
    }

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            if (sz(g[i]) == k) {
                cout << char(i + 'A');
            }
        }
    }
    cout << "\n";

}