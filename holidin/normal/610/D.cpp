#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
const int inf = 1e9 + 1;
const int mod = 1e9 + 7;

mt19937 rnd(58);
map <int, vector <pair<int, int> > > mh, mv;
int x[N], y[N];

vector <pair<int, int> > conv(vector<pair<int, int> > &v) {
    sort(v.begin(), v.end());
    int i = 0;
    vector <pair<int, int> > ans;
    while (i < v.size()) {
        int j = i;
        int mx = v[i].se;
        while (j < v.size() && v[j].fi <= mx) {
            mx = max(mx, v[j].se);
            ++j;
        }
        ans.push_back({v[i].fi, mx});
        i = j;
    }
    return ans;
}

int sum(vector <pair<int, int> > &v) {
    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
        ans += v[i].se - v[i].fi + 1;
    return ans;
}

map <int, int> fenw;

int f(int i) {
    return i & (-i);
}

int sumf(int i) {
    int ans = 0;
    while (i > 0) {
        ans += fenw[i];
        i -= f(i);
    }
    return ans;
}

void addf(int i, int x) {
    while (i <= 2 * inf) {
        fenw[i] += x;
        i += f(i);
    }
}


void solve() {
    int i, j, k, n, x1, y1;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        cin >> x1 >> y1;
        x[i] += inf;
        y[i] += inf;
        x1 += inf;
        y1 += inf;
        if (x[i] > x1)
            swap(x[i], x1);
        if (y[i] > y1)
            swap(y[i], y1);
        if (x[i] == x1) {
            mv[x[i]].push_back({y[i], y1});
        } else {
            mh[y[i]].push_back({x[i], x1});
        }
    }
    int ans = 0;
    for (auto it = mh.begin(); it != mh.end(); ++it) {
        (*it).se = conv((*it).se);
        ans += sum((*it).se);
    }
    for (auto it = mv.begin(); it != mv.end(); ++it) {
        (*it).se = conv((*it).se);
        ans += sum((*it).se);
    }
    vector <pair<int, int> > event;
    for (auto it = mv.begin(); it != mv.end(); ++it) {
        for (j = 0; j < (*it).se.size(); ++j) {
            event.push_back({(*it).se[j].fi, (*it).fi});
            event.push_back({(*it).se[j].se + 1, -(*it).fi});
        }
    }
    sort(event.begin(), event.end());
    int l = 0;
    for (auto it = mh.begin(); it != mh.end(); ++it) {
        while (l < event.size() && event[l].fi <= (*it).fi) {
            if (event[l].se > 0)
                addf(event[l].se, 1);
            else
                addf(-event[l].se, -1);
            ++l;
        }
        for (j = 0; j < (*it).se.size(); ++j) {
            ans -= sumf((*it).se[j].se) - sumf((*it).se[j].fi - 1);
        }
    }
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}