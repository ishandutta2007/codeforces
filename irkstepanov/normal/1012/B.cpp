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

//typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef int ll;
//typedef pair<ll, ll> pll;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int cnt = 0;
    vector<set<int> > a(n);
    vector<set<int> > b(m);

    int q;
    cin >> q;
    vector<pii> v(q);
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        a[x].insert(y);
        b[y].insert(x);
        v[i] = {x, y};
    }

    set<int> cols, rows;

    for (int i = 0; i < q; ++i) {
        int x = v[i].first, y = v[i].second;
        if (!a[x].count(y)) {
            continue;
        }
        a[x].erase(y);
        b[y].erase(x);
        rows.insert(x);
        cols.insert(y);
        queue<pii> qu;
        qu.push({x, y});
        while (!qu.empty()) {
            x = qu.front().first, y = qu.front().second;
            qu.pop();
            for (int z : a[x]) {
                cols.insert(z);
                qu.push({x, z});
            }
            a[x].clear();
            for (int z : b[y]) {
                rows.insert(z);
                qu.push({z, y});
            }
            b[y].clear();
        }
        ++cnt;
    }

    int ans = max(n - sz(rows), m - sz(cols));
    cnt += min(n - sz(rows), m - sz(cols));

    ans += (cnt - 1);
    cout << ans << "\n";

}