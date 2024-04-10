#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

ll count(int x, int y, int n, int m, int r) {
    ll mina = max(1, x - r + 1);
    ll maxa = min(x, n - r + 1);
    ll minb = max(1, y - r + 1);
    ll maxb = min(y, m - r + 1);
    if (mina <= maxa && minb <= maxb) {
        return (maxa - mina + 1) * (maxb - minb + 1);
    } else {
        return 0;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, r, k;
    cin >> n >> m >> r >> k;

    auto comp = [&] (pii a, pii b) {
        ll x = count(a.first, a.second, n, m, r);
        ll y = count(b.first, b.second, n, m, r);
        if (x != y) {
            return x > y;
        }
        return a < b;
    };

    set<pii> used;
    set<pii, decltype(comp)> q(comp);
    ll sum = 0;
    int cnt = 0;
    for (int x = max(1, n / 2 - 3); x <= min(n / 2 + 3, n); ++x) {
        for (int y = max(1, m / 2 - 3); y <= min(m / 2 + 3, m); ++y) {
            q.insert({x, y});
            used.insert({x, y});
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (cnt < k) {
        pii p = *q.begin();
        q.erase(q.begin());
        ++cnt;
        sum += count(p.first, p.second, n, m, r);
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !used.count({xx, yy})) {
                used.insert({xx, yy});
                q.insert({xx, yy});
            }
        }
    }

    ld ans = ld(sum) / (n - r + 1) / (m - r + 1);
    cout << fixed;
    cout.precision(20);
    cout << ans << "\n";

}