#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int inf = 1e9 + 10;

void remin(int& x, int y) {
    x = min(x, y);
}

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
        int n;
        cin >> n;
        int l = inf, r = -inf;
        int costl = 0, costr = 0;
        map<pii, int> mapa;
        for (int i = 0; i < n; ++i) {
            int x, y, c;
            cin >> x >> y >> c;
            if (x < l) {
                l = x;
                costl = c;
            } else if (x == l) {
                costl = min(costl, c);
            }
            if (y > r) {
                r = y;
                costr = c;
            } else if (y == r) {
                costr = min(costr, c);
            }
            if (!mapa.count({x, y})) {
                mapa[{x, y}] = c;
            } else {
                remin(mapa[{x, y}], c);
            }
            int ans = costl + costr;
            if (mapa.count({l, r})) {
                ans = min(ans, mapa[{l, r}]);
            }
            cout << ans << "\n";
        }
    }

}