#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    ll k;
    cin >> k;
    int x, y;
    cin >> x >> y;
    --x, --y;

    int a[3][3], b[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> b[i][j];
            --b[i][j];
        }
    }

    if (k < 100500) {
        int f1 = 0, f2 = 0;
        while (k--) {
            if (x != y) {
                if ((x + 2) % 3 == y) {
                    ++f1;
                } else {
                    ++f2;
                }
            }
            int nx = a[x][y];
            int ny = b[x][y];
            x = nx, y = ny;
        }
        cout << f1 << " " << f2 << "\n";
        return 0;
    }

    map<pii, int> mapa;
    mapa[{x, y}] = 0;
    int first, len;
    int curr = 1;
    int initX = x, initY = y;
    while (true) {
        int nx = a[x][y];
        int ny = b[x][y];
        //cout << "!" << x << " " << y << " " << nx << " " << ny << "\n";
        if (mapa.count({nx, ny})) {
            first = mapa[{nx, ny}];
            len = curr - mapa[{nx, ny}];
            break;
        }
        x = nx, y = ny;
        mapa[{x, y}] = curr;
        ++curr;
    }

    x = initX, y = initY;

    ll f1 = 0, f2 = 0;
    for (int i = 0; i < first; ++i) {
        if (x != y) {
            if ((x + 2) % 3 == y) {
                ++f1;
            } else {
                ++f2;
            }
        }
        int nx = a[x][y];
        int ny = b[x][y];
        x = nx, y = ny;
    }
    //cout << "!" << f1 << " " << f2 << "\n";

    //cout << first << " " << len << "\n";

    k -= first;
    ll df1 = 0, df2 = 0;
    for (int i = 0; i < len; ++i) {
        if (x != y) {
            if ((x + 2) % 3 == y) {
                ++df1;
            } else {
                ++df2;
            }
        }
        int nx = a[x][y];
        int ny = b[x][y];
        x = nx, y = ny;
    }

    f1 += df1 * (k / len);
    f2 += df2 * (k / len);
    //cout << f1 << " " << f2 << "\n";
    for (int i = 0; i < k % len; ++i) {
        if (x != y) {
            if ((x + 2) % 3 == y) {
                ++f1;
            } else {
                ++f2;
            }
        }
        int nx = a[x][y];
        int ny = b[x][y];
        x = nx, y = ny;
    }

    cout << f1 << " " << f2 << "\n";

}