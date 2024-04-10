#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

void gen(const vector<int>& lo, const vector<int>& hi, vector<int>& curr, vector<vector<int> >& ans) {
    if (sz(curr) == sz(lo)) {
        ans.pb(curr);
        return;
    }
    int i = sz(curr);
    for (int x = lo[i]; x <= hi[i]; ++x) {
        curr.pb(x);
        gen(lo, hi, curr, ans);
        curr.pop_back();
    }
}

int getCost(int a, int c) {
    if (c == 0) {
        return 0;
    }
    return a + c * c;
}

const int inf = 1e9;
vector<int> limits;

bool valid(const vector<int>& vct) {
    for (int i = 0; i < sz(vct); ++i) {
        if (vct[i] < 0 || vct[i] > limits[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    map<vector<int>, int> dist;
    vector<int> vct = {0};
    dist[vct] = 0;
    auto comp = [&] (const vector<int>& a, const vector<int>& b) {
        if (sz(a) != sz(b)) {
            return sz(a) < sz(b);
        }
        return a < b;
    };
    set<vector<int>, decltype(comp)> q(comp);
    q.insert(vct);

    int n;
    cin >> n;

    if (n == 2) {
        limits = {inf, inf};
    } else if (n == 3) {
        limits = {inf, 5, inf};
    } else if (n == 4) {
        limits = {inf, 5, 5, inf};
    } else if (n == 5) {
        limits = {inf, 5, 10, 5, inf};
    } else {
        limits = {inf, 5, 10, 10, 5, inf};
    }

    vector<vector<int> > lo(n, vector<int>(n)), hi(n, vector<int>(n)), a(n, vector<int>(n));
    for (int i = 0; i < n * (n - 1) / 2; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cin >> lo[u][v] >> hi[u][v] >> a[u][v];
    }

    int ans1 = inf, ans2 = -inf;

    while (!q.empty()) {
        vct = *q.begin();
        q.erase(q.begin());
        if (sz(vct) == n) {
            bool ok = true;
            for (int i = 1; i < n - 1; ++i) {
                if (vct[i] > 0) {
                    ok = false;
                }
            }
            if (!ok) {
                continue;
            }
            if (vct[0] < ans1 || (vct[0] == ans1 && dist[vct] > ans2)) {
                ans1 = vct[0];
                ans2 = dist[vct];
            }
            continue;
        }
        int k = sz(vct);
        vector<int> l, h;
        for (int i = 0; i < k; ++i) {
            l.pb(lo[i][k]);
            h.pb(hi[i][k]);
        }
        vector<vector<int> > total;
        if (k == n - 1) {
            for (int x = lo[0][k]; x <= hi[0][k]; ++x) {
                vector<int> tmp = {x};
                bool ok = true;
                for (int i = 1; i < k; ++i) {
                    if (vct[i] < lo[i][k] || vct[i] > hi[i][k]) {
                        ok = false;
                    }
                    tmp.pb(vct[i]);
                }
                if (ok) {
                    total.pb(tmp);
                }
            }
        } else {
            vector<int> tmp = {};
            gen(l, h, tmp, total);
        }
        int init = dist[vct];

        for (vector<int> tmp : total) {
            vector<int> nx;
            nx.pb(vct[0] + tmp[0]);
            int cost = getCost(a[0][k], tmp[0]);
            int sum = tmp[0];
            for (int i = 1; i < k; ++i) {
                nx.pb(vct[i] - tmp[i]);
                cost += getCost(a[i][k], tmp[i]);
                sum += tmp[i];
            }
            nx.pb(sum);
            if (!valid(nx)) {
                continue;
            }
            if (!dist.count(nx) || dist[nx] < cost + init) {
                dist[nx] = cost + init;
                q.insert(nx);
            }
        }
    }

    if (ans1 == inf) {
        cout << "-1 -1\n";
    } else {
        cout << ans1 << " " << ans2 << "\n";
    }

}