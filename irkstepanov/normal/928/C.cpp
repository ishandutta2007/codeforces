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
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

/*struct node {
    int promise;
    int sum;
    node() : promise(0), sum(0) {}
};

vector<node> t;

void upd(int v, int tl, int tr) {
    t[v].sum = tr - tl + 1;
    t[v].promise = 1;
}

void push(int v, int tl, int tr) {
    if (t[v].promise == 0) {
        return;
    }
    int tm = (tl + tr) >> 1;
    upd(v * 2, tl, tm);
    upd(v * 2 + 1, tm + 1, tr);
    t[v].promise = 0;
}

void assign(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        t[v].sum = tr - tl + 1;
        t[v].promise = 1;
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        assign(v * 2, tl, tm, l, min(r, tm));
    }
    if (r > tm) {
        assign(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
}*/

const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<string> s(n);
    vector<int> v(n);
    map<pair<string, int>, int> mapa;

    vector<vector<pair<string, int> > > edges(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        cin >> v[i];
        int k;
        cin >> k;
        while (k--) {
            string ss;
            int vv;
            cin >> ss;
            cin >> vv;
            edges[i].pb({ss, vv});
        }
        mapa[{s[i], v[i]}] = i;
    }

    vector<vector<int> > g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(edges[i]); ++j) {
            g[i].pb(mapa[edges[i][j]]);
        }
    }

    set<string> done;
    done.insert(s[0]);
    vector<pair<string, int> > ans;

    queue<int> q[2];
    q[0].push(0);

    int ptr = 0;
    while (!q[ptr].empty()) {
        map<string, int> best;
        while (!q[ptr].empty()) {
            int w = q[ptr].front();
            q[ptr].pop();
            for (int to : g[w]) {
                if (done.count(s[to])) {
                    continue;
                }
                if (!best.count(s[to])) {
                    best[s[to]] = v[to];
                } else {
                    best[s[to]] = max(best[s[to]], v[to]);
                }
            }
        }
        for (auto it : best) {
            ans.pb({it.first, it.second});
            done.insert(it.first);
            q[ptr ^ 1].push(mapa[it]);
        }
        ptr ^= 1;
    }

    sort(all(ans));
    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

}