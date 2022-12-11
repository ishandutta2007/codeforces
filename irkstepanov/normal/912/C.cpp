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

struct event {
    ll t;
    char type;
    bool operator<(const event& other) const {
        if (t != other.t) {
            return t < other.t;
        }
        if (type != other.type) {
            return type == '+';
        }
        return false;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    ll bounty, increase, damage;
    cin >> bounty >> increase >> damage;

    vector<ll> maxx(n), start(n), regen(n);
    for (int i = 0; i < n; ++i) {
        cin >> maxx[i] >> start[i] >> regen[i];
        if (maxx[i] <= damage && increase) {
            cout << "-1\n";
            return 0;
        }
    }

    vector<vector<pll> > r(n);
    while (q--) {
        ll t, id, h;
        cin >> t >> id >> h;
        --id;
        r[id].pb({t, h});
    }

    for (int i = 0; i < n; ++i) {
        sort(all(r[i]));
    }

    vector<event> events;
    for (int i = 0; i < n; ++i) {
        ll h = start[i];
        ll t = 0;
        for (int j = 0; j < sz(r[i]); ++j) {
            if (h <= damage) {
                ll x = r[i][j].first - t - 1;
                if (regen[i] != 0) {
                    x = min(x, (damage - h) / regen[i]);
                }
                events.pb({t, '+'});
                events.pb({t + x, '-'});
            }
            h = r[i][j].second;
            t = r[i][j].first;
        }

        if (h <= damage && regen[i] == 0 && increase) {
            cout << "-1\n";
            return 0;
        }
        if (h <= damage) {
            if (regen[i] == 0) {
                events.pb({t, '+'});
            } else {
                ll x = (damage - h) / regen[i];
                events.pb({t, '+'});
                events.pb({t + x, '-'});
            }
        }
    }

    sort(all(events));
    ll ans = 0;
    int cnt = 0;
    for (event& e : events) {
        ans = max(ans, ll(cnt) * bounty + ll(cnt) * e.t * increase);
        if (e.type == '+') {
            ++cnt;
        } else {
            --cnt;
        }
        //cout << e.t << " " << cnt << "\n";
        ans = max(ans, ll(cnt) * bounty + ll(cnt) * e.t * increase);
    }

    cout << ans << "\n";

}