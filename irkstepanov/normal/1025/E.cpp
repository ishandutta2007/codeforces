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
typedef long double ld;
typedef pair<ld, ld> pld;

struct ddata {
    int x1, y1;
    int x2, y2;
};

const int nmax = 55;

int occ[nmax][nmax];
int x[nmax], y[nmax];
int tx[nmax], ty[nmax];

bool comp(int a, int b) {
    return tie(tx[a], ty[a]) < tie(tx[b], ty[b]);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            occ[i][j] = -1;
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> x[i] >> y[i];
        --x[i], --y[i];
        occ[x[i]][y[i]] = i;
    }

    for (int i = 0; i < m; ++i) {
        cin >> tx[i] >> ty[i];
        --tx[i], --ty[i];
    }

    vector<ddata> ans;
    int mid = n / 2;
    vector<int> order(m);
    for (int i = 0; i < m; ++i) {
        order[i] = i;
    }
    sort(all(order), [&] (int a, int b) {
        if (y[a] != y[b]) {
            return y[a] < y[b];
        }
        return a < b;
    });
    vector<int> pos(m);
    for (int i = 0; i < m; ++i) {
        pos[order[i]] = i;
    }

    while (true) {
        bool term = true;
        for (int i = 0; i < m; ++i) {
            if (y[i] != pos[i]) {
                term = false;
                break;
            }
        }
        if (term) {
            break;
        }
        bool done = false;
        for (int i = 0; i < m; ++i) {
            if (y[i] == pos[i]) {
                continue;
            }
            if (y[i] > pos[i]) {
                if (occ[x[i]][y[i] - 1] == -1) {
                    done = true;
                    occ[x[i]][y[i]] = -1;
                    ans.pb({x[i], y[i], x[i], y[i] - 1});
                    --y[i];
                    occ[x[i]][y[i]] = i;
                }
            }
            if (y[i] < pos[i]) {
                if (occ[x[i]][y[i] + 1] == -1) {
                    done = true;
                    occ[x[i]][y[i]] = -1;
                    ans.pb({x[i], y[i], x[i], y[i] + 1});
                    ++y[i];
                    occ[x[i]][y[i]] = i;
                }
            }
        }
        assert(done);
    }

    for (int i = 0; i < m; ++i) {
        while (x[i] != mid) {
            if (x[i] > mid) {
                occ[x[i]][y[i]] = -1;
                ans.pb({x[i], y[i], x[i] - 1, y[i]});
                --x[i];
                occ[x[i]][y[i]] = i;
            } else {
                occ[x[i]][y[i]] = -1;
                ans.pb({x[i], y[i], x[i] + 1, y[i]});
                ++x[i];
                occ[x[i]][y[i]] = i;
            }
        }
    }

    sort(all(order), comp);
    for (int i = 0; i < m; ++i) {
        pos[order[i]] = i;
    }

    while (true) {
        bool term = true;
        for (int i = 0; i < m; ++i) {
            if (y[i] != pos[i]) {
                term = false;
                break;
            }
        }
        if (term) {
            break;
        }
        for (int i = 0; i + 1 < m; ++i) {
            int a = occ[mid][i], b = occ[mid][i + 1];
            if (pos[a] > pos[b]) {
                int d;
                if (mid + 1 < n) {
                    d = 1;
                } else {
                    d = -1;
                }
                ans.pb({x[b], y[b], x[b] + d, y[b]});
                ans.pb({x[b] + d, y[b], x[b] + d, y[b] - 1});
                ans.pb({x[a], y[a], x[a], y[a] + 1});
                ans.pb({x[b] + d, y[b] - 1, x[a], y[a]});
                swap(occ[x[a]][y[a]], occ[x[b]][y[b]]);
                swap(y[a], y[b]);
            }
        }
    }

    int rg = m - 1;
    while (rg >= 0) {
        if (tx[occ[mid][rg]] <= mid) {
            break;
        }
        int lf = rg;
        while (lf - 1 >= 0 && tx[occ[mid][lf - 1]] == tx[occ[mid][rg]]) {
            --lf;
        }
        vector<int> ids;
        for (int i = lf; i <= rg; ++i) {
            int a = occ[mid][i];
            ids.pb(a);
            while (x[a] != tx[a]) {
                if (x[a] < tx[a]) {
                    ans.pb({x[a], y[a], x[a] + 1, y[a]});
                    swap(occ[x[a]][y[a]], occ[x[a] + 1][y[a]]);
                    ++x[a];
                } else {
                    ans.pb({x[a], y[a], x[a] - 1, y[a]});
                    swap(occ[x[a]][y[a]], occ[x[a] - 1][y[a]]);
                    --x[a];
                }
            }
        }
        while (true) {
            bool term = true;
            for (int i : ids) {
                if (y[i] != ty[i]) {
                    term = false;
                    break;
                }
            }
            if (term) {
                break;
            }
            for (int i : ids) {
                if (y[i] > ty[i] && occ[x[i]][y[i] - 1] == -1) {
                    ans.pb({x[i], y[i], x[i], y[i] - 1});
                    swap(occ[x[i]][y[i]], occ[x[i]][y[i] - 1]);
                    --y[i];
                }
                if (y[i] < ty[i] && occ[x[i]][y[i] + 1] == -1) {
                    ans.pb({x[i], y[i], x[i], y[i] + 1});
                    swap(occ[x[i]][y[i]], occ[x[i]][y[i] + 1]);
                    ++y[i];
                }
            }
        }
        rg = lf - 1;
    }

    int lf = 0;
    while (lf < m) {
        if (tx[occ[mid][lf]] > mid) {
            break;
        }
        rg = lf;
        while (rg + 1 < m && tx[occ[mid][rg + 1]] == tx[occ[mid][lf]]) {
            ++rg;
        }
        vector<int> ids;
        for (int i = lf; i <= rg; ++i) {
            int a = occ[mid][i];
            ids.pb(a);
            while (x[a] != tx[a]) {
                if (x[a] < tx[a]) {
                    ans.pb({x[a], y[a], x[a] + 1, y[a]});
                    swap(occ[x[a]][y[a]], occ[x[a] + 1][y[a]]);
                    ++x[a];
                } else {
                    ans.pb({x[a], y[a], x[a] - 1, y[a]});
                    swap(occ[x[a]][y[a]], occ[x[a] - 1][y[a]]);
                    --x[a];
                }
            }
        }
        while (true) {
            bool term = true;
            for (int i : ids) {
                if (y[i] != ty[i]) {
                    term = false;
                    break;
                }
            }
            if (term) {
                break;
            }
            for (int i : ids) {
                if (y[i] > ty[i] && occ[x[i]][y[i] - 1] == -1) {
                    ans.pb({x[i], y[i], x[i], y[i] - 1});
                    swap(occ[x[i]][y[i]], occ[x[i]][y[i] - 1]);
                    --y[i];
                }
                if (y[i] < ty[i] && occ[x[i]][y[i] + 1] == -1) {
                    ans.pb({x[i], y[i], x[i], y[i] + 1});
                    swap(occ[x[i]][y[i]], occ[x[i]][y[i] + 1]);
                    ++y[i];
                }
            }
        }
        lf = rg + 1;
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].x1 + 1 << " " << ans[i].y1 + 1 << " " << ans[i].x2 + 1 << " " << ans[i].y2 + 1 << "\n";
    }

}