#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        int x, y;
        cin >> n >> m >> x >> y;
        --x, --y;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (a[x][y] == 'B') {
            cout << "0\n";
        } else {
            bool ok = false;
            bool all_white = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] != 'B') {
                        continue;
                    }
                    all_white = false;
                    if (i == x || j == y) {
                        ok = true;
                    }
                }
            }
            if (all_white) {
                cout << "-1\n";
            } else if (ok) {
                cout << "1\n";
            } else {
                cout << "2\n";
            }
        }
    }

}