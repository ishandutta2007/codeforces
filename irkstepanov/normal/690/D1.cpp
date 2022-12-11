#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const int nmax = 110;

int main()
{

    //freopen("input.txt", "r", stdin);

    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;

    char a[nmax][nmax];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    bool prev = false;
    for (int j = 0; j < m; ++j) {
        if (a[n - 1][j] == 'B') {
            if (!prev) {
                prev = true;
                ++ans;
            }
        } else {
            prev = false;
        }
    }

    cout << ans << "\n";

}