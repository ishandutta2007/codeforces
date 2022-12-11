#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char> > a(n, vector<char>(m));
        vector<int> x1, x2, y1, y2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 1; --j) {
                if (a[i][j] == '1') {
                    x1.pb(i), x2.pb(i);
                    y1.pb(j - 1), y2.pb(j);
                }
            }
        }
        for (int i = n - 1; i >= 1; --i) {
            if (a[i][0] == '1') {
                x1.pb(i - 1), x2.pb(i);
                y1.pb(0), y2.pb(0);
            }
        }
        if (a[0][0] == '1') {
            cout << "-1\n";
            continue;
        }
        cout << sz(x1) << "\n";
        for (int i = 0; i < sz(x1); ++i) {
            cout << x1[i] + 1 << " " << y1[i] + 1 << " " << x2[i] + 1 << " " << y2[i] + 1 << "\n";
        }
    }

}