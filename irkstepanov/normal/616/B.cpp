#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int inf = (int) (1e9 + 5);

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int x = inf;
        for (int j = 0; j < m; ++j) {
            x = min(x, a[i][j]);
        }
        ans = max(ans, x);
    }
    cout << ans << "\n";

}