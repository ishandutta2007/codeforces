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

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<char> > a(n, vector<char>(m, false));
    map<string, pii> pos;

    while (q--) {
        string type;
        cin >> type;
        if (type == "-1") {
            string s;
            cin >> s;
            if (pos.count(s)) {
                int x = pos[s].first, y = pos[s].second;
                a[x][y] = false;
                pos.erase(s);
                cout << x + 1 << " " << y + 1 << '\n';
            } else {
                cout << "-1 -1\n";
            }
        } else {
            int x, y;
            cin >> x >> y;
            --x, --y;
            string s;
            cin >> s;
            bool ok = false;
            for (int j = y; j < m; ++j) {
                if (!a[x][j]) {
                    a[x][j] = true;
                    pos[s] = mp(x, j);
                    ok = true;
                    break;
                }
            }
            if (ok) {
                continue;
            }
            for (int i = x + 1; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!a[i][j]) {
                        a[i][j] = true;
                        pos[s] = mp(i, j);
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    break;
                }
            }
        }
    }

}