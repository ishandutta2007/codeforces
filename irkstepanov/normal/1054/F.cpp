#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct segment {
    int x1, y1;
    int x2, y2;
};

vector<vector<int> > g;
vector<bool> used;
vector<int> mt;
vector<int> corr;

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || dfs(mt[to])) {
            mt[to] = v;
            corr[v] = to;
            return true;
        }
    }
    return false;
}

vector<bool> usedL, usedR;

void vis(int v) {
    usedL[v] = true;
    for (int to : g[v]) {
        if (mt[to] == v) {
            continue;
        }
        usedR[to] = true;
        if (mt[to] != -1 && !usedL[mt[to]]) {
            vis(mt[to]);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    map<int, vector<int> > hor, ver;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        hor[y].pb(x);
        ver[x].pb(y);
    }

    vector<segment> v1, v2;
    for (map<int, vector<int> >::iterator it = hor.begin(); it != hor.end(); ++it) {
        sort(all(it->second));
        for (int i = 0; i + 1 < sz(it->second); ++i) {
            v1.pb({it->second[i], it->first, it->second[i + 1], it->first});
        }
    }
    for (map<int, vector<int> >::iterator it = ver.begin(); it != ver.end(); ++it) {
        sort(all(it->second));
        for (int i = 0; i + 1 < sz(it->second); ++i) {
            v2.pb({it->first, it->second[i], it->first, it->second[i + 1]});
        }
    }

    mt.assign(sz(v2), -1);
    g.resize(sz(v1));
    corr.assign(sz(v1), -1);
    for (int i = 0; i < sz(v1); ++i) {
        for (int j = 0; j < sz(v2); ++j) {
            if (v2[j].x1 > v1[i].x1 && v2[j].x1 < v1[i].x2 && v1[i].y1 > v2[j].y1 && v1[i].y1 < v2[j].y2) {
                g[i].pb(j);
            }
        }
    }

    while (true) {
        used.assign(sz(v1), false);
        bool found = false;
        for (int i = 0; i < sz(v1); ++i) {
            if (corr[i] != -1) {
                continue;
            }
            if (dfs(i)) {
                found = true;
            }
        }
        if (!found) {
            break;
        }
    }

    usedL.assign(sz(v1), false);
    usedR.assign(sz(v2), false);
    for (int i = 0; i < sz(v1); ++i) {
        if (corr[i] == -1 && !usedL[i]) {
            vis(i);
        }
    }

    vector<segment> ans;
    int ptr = 0;
    for (map<int, vector<int> >::iterator it = hor.begin(); it != hor.end(); ++it) {
        int y = it->first;
        int xl = it->second[0], xr = it->second[0];
        for (int i = 0; i + 1 < sz(it->second); ++i) {
            if (usedL[ptr]) {
                xr = it->second[i + 1];
            } else {
                ans.pb({xl, y, xr, y});
                xl = xr = it->second[i + 1];
            }
            ++ptr;
        }
        ans.pb({xl, y, xr, y});
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].x1 << " " << ans[i].y1 << " " << ans[i].x2 << " " << ans[i].y2 << "\n";
    }

    ans.clear();
    ptr = 0;

    for (map<int, vector<int> >::iterator it = ver.begin(); it != ver.end(); ++it) {
        int x = it->first;
        int yl = it->second[0], yr = it->second[0];
        for (int i = 0; i + 1 < sz(it->second); ++i) {
            if (!usedR[ptr]) {
                yr = it->second[i + 1];
            } else {
                ans.pb({x, yl, x, yr});
                yl = yr = it->second[i + 1];
            }
            ++ptr;
        }
        ans.pb({x, yl, x, yr});
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].x1 << " " << ans[i].y1 << " " << ans[i].x2 << " " << ans[i].y2 << "\n";
    }
    
}