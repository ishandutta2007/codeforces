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

const int nmax = 60;
const int inf = 1e9;

int pref[nmax][nmax];
int n, m;
int a, b;

int get(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> pref[i][j];
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    cin >> a >> b;

    int ans = inf;
    --a, --b;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i + a <= n && j + b <= m) {
                ans = min(ans, get(i, j, i + a, j + b));
            }
            if (i + b <= n && j + a <= m) {
                ans = min(ans, get(i, j, i + b, j + a));
            }
        }
    }
    cout << ans << "\n";

}