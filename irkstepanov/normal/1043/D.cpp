#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > a(m);
    vector<vector<int> > rev(m);

    for (int i = 0; i < m; ++i) {
        a[i].resize(n);
        rev[i].resize(n);
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            --x;
            a[i][j] = x;
            rev[i][x] = j;
        }
    }

    ll ans = 0;
    int r = 0;
    for (int l = 0; l < n; ++l) {
        vector<int> ptr(m);
        if (r < l) {
            r = l;
        }
        for (int j = 1; j < m; ++j) {
            ptr[j] = rev[j][a[0][l]];
        }
        while (r + 1 < n) {
            bool ok = true;
            for (int j = 1; j < m; ++j) {
                int pos = ptr[j] + r - l + 1;
                if (pos >= n || a[j][pos] != a[0][r + 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ++r;
            } else {
                break;
            }
        }
        ans += (r - l + 1);
    }

    cout << ans << "\n";

}