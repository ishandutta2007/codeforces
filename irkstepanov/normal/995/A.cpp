#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

struct data {
    int id, x, y;
};

vector<data> ans;

vector<vector<int> > v;
vector<pii> a;
int n;
int z;

void put() {
    for (int j = 0; j < n; ++j) {
        if (v[0][j] == 0) {
            continue;
        }
        int x = v[0][j];
        if (a[x].first == 1 && a[x].second == j) {
            ans.pb({x, 1, j + 1});
            v[0][j] = 0;
            --z;
        }
    }
    for (int j = 0; j < n; ++j) {
        if (v[1][j] == 0) {
            continue;
        }
        int x = v[1][j];
        if (a[x].first == 4 && a[x].second == j) {
            ans.pb({x, 4, j + 1});
            v[1][j] = 0;
            --z;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> n >> k;

   a.resize(k + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x != 0) {
            a[x] = {1, i};
        }
    }

    v = vector<vector<int> >(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            v[i][j] = x;
        }
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x != 0) {
            a[x] = {4, i};
        }
    }

    z = k;
    put();
    if (z == 2 * n) {
        cout << "-1\n";
        return 0;
    }

    while (z) {
        int x0 = -1, y0 = -1;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (v[i][j] == 0) {
                    x0 = i, y0 = j;
                }
            }
        }
        assert(x0 != -1 && y0 != -1);
        for (int s = 0; s < 2 * n - 1; ++s) {
            int x, y;
            if (x0 == 1 && y0 != n - 1) {
                x = x0, y = y0 + 1;
            } else if (x0 == 1) {
                x = 0, y = y0;
            } else if (x0 == 0 && y0 != 0) {
                x = x0, y = y0 - 1;
            } else if (x0 == 0) {
                x = 1, y = y0;
            }
            if (v[x][y] == 0) {
                x0 = x, y0 = y;
                continue;
            }
            v[x0][y0] = v[x][y];
            ans.pb({v[x][y], x0 + 2, y0 + 1});
            v[x][y] = 0;
            x0 = x, y0 = y;
        }
        put();
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].id << " " << ans[i].x << " " << ans[i].y << "\n";
    }

}