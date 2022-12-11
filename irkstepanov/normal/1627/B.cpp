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
        cin >> n >> m;
        vector<vector<int> > a(n, vector<int>(m));
        vector<int> vals;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = max(i, n - 1 - i) + max(j, m - 1 - j);
                vals.pb(a[i][j]);
            }
        }
        sort(all(vals));
        for (int x = 0; x < n * m; ++x) {
            cout << vals[x] << " ";
        }
        cout << "\n";
    }

}