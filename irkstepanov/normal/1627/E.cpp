#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct ladder {
    int i1, j1;
    int i2, j2;
    ll h;
    bool operator<(const ladder& other) const {
        return j1 < other.j1;
    }
};

struct event {
    int i, j;
    ll val;
};

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<ll> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        vector<vector<ladder> > ladders(n);
        for (int i = 0; i < q; ++i) {
            int i1, j1, i2, j2;
            ll h;
            cin >> i1 >> j1 >> i2 >> j2 >> h;
            --i1, --j1, --i2, --j2;
            ladders[i1].pb({i1, j1, i2, j2, h});
        }
        ladders[n - 1].pb({n - 1, m - 1, n - 1, m - 1, 0});
        vector<vector<event> > events(n);
        events[0].pb({0, 0, 0});
        ll ans = inf;

        for (int i = 0; i < n; ++i) {
            if (events[i].empty()) {
                continue;
            }
            map<int, ll> mapa;
            for (event& e : events[i]) {
                if (!mapa.count(e.j)) {
                    mapa[e.j] = e.val;
                } else {
                    mapa[e.j] = min(mapa[e.j], e.val);
                }
            }
            sort(all(ladders[i]));
            map<int, ll> cost;
            int pos = 0;
            ll val = inf;
            map<int, ll>::iterator it = mapa.begin();

            for (ladder& l : ladders[i]) {
                while (it != mapa.end() && it->first <= l.j1) {
                    ll old = val + x[i] * (l.j1 - pos);
                    ll nx = it->second + x[i] * (l.j1 - it->first);
                    if (nx < old) {
                        pos = it->first;
                        val = it->second;
                    }
                    ++it;
                }
                cost[l.j1] = val + x[i] * (l.j1 - pos);
            }

            it = --mapa.end();
            reverse(all(ladders[i]));
            pos = m - 1;
            val = inf;

            for (ladder& l : ladders[i]) {
                while (true && it->first >= l.j1) {
                    ll old = val + x[i] * (pos - l.j1);
                    ll nx = it->second + x[i] * (it->first - l.j1);
                    if (nx < old) {
                        pos = it->first;
                        val = it->second;
                    }
                    if (it == mapa.begin()) {
                        break;
                    } else {
                        --it;
                    }
                }
                if (!cost.count(l.j1)) {
                    cost[l.j1] = val + x[i] * (pos - l.j1);
                } else {
                    cost[l.j1] = min(cost[l.j1], val + x[i] * (pos - l.j1));
                }
            }

            for (ladder& l : ladders[i]) {
                events[l.i2].pb({l.i2, l.j2, cost[l.j1] - l.h});
            }

            if (i == n - 1) {
                ans = min(ans, cost[m - 1]);
            }
        }
        if (ans == inf) {
            cout << "NO ESCAPE\n";
        } else {
            cout << ans << "\n";
        }
    }

}