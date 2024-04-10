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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> rem(m);
    vector<vector<int> > start(n);
    vector<int> finish(n, -1);
    vector<int> e(m);

    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        --x, --y;
        rem[i] = c;
        start[x].pb(i);
        finish[y] = i;
        e[i] = y;
    }

    vector<bool> active(m, false);
    vector<int> ans(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int x : start[i]) {
            active[x] = true;
        }
        if (finish[i] != -1) {
            ans[i] = m + 1;
            active[finish[i]] = false;
            continue;
        }
        int w = -1;
        for (int j = 0; j < m; ++j) {
            if (!active[j]) {
                continue;
            }
            if (w == -1 || e[j] < e[w]) {
                w = j;
            }
        }
        if (w == -1) {
            ans[i] = 0;
            continue;
        }
        ans[i] = w + 1;
        --rem[w];
        if (rem[w] == 0) {
            active[w] = false;
        }
    }

    bool ok = true;
    for (int i = 0; i < m; ++i) {
        if (rem[i]) {
            ok = false;
        }
    }

    if (!ok) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}