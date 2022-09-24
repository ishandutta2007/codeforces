#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

template <typename T>
struct fenwick {
    int n;
    vector<T> f;

    fenwick() {}

    fenwick(int N) {
        n = N;
        f.assign(N, T(0));
    }

    fenwick(vector<T> a) {
        n = a.size();
        for (int i = 0; i < n; i++) add(i, a[i]);
    }

    void add(int x, T y) {
        for (; x < n; x |= x + 1) f[x] += y;
    }

    T get(int x) {
        T res(0);
        for (; x >= 0; x = (x & (x + 1)) - 1) res += f[x];
        return res;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    // return min i: sum(0, i) > x
    int upper_bound(T x) {
        int k = 1;
        while (2 * k <= n) k *= 2;

        int res = 0;
        while (k > 0) {
            if (f[res + k - 1] <= x) {
                x -= f[res + k - 1];
                res += k;
            }
            k /= 2;
        }
        return res;
    }
};


ll solve(vector<pair<int, int>> a) {
    int n = a.size();

    vector<int> xx, yy;
    for (auto o : a) {
        xx.push_back(o.first);
        yy.push_back(o.second);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
    yy.resize(unique(yy.begin(), yy.end()) - yy.begin());
    for (auto &o : a) {
        o.first = lower_bound(xx.begin(), xx.end(), o.first) - xx.begin();
        o.second = lower_bound(yy.begin(), yy.end(), o.second) - yy.begin();
    }
    int nx = xx.size(), ny = yy.size();

    vector<vector<int>> vct(ny);
    for (int i = 0; i < n; i++) {
        vct[a[i].second].push_back(i);
    }

    ll ans = 0;
    fenwick<int> f(nx);
    vector<int> af(nx);
    for (int i = ny - 1; i >= 0; i--) {
        vector<int> cx;
        for (int id : vct[i]) {
            cx.push_back(a[id].first);
        }
        sort(cx.begin(), cx.end());
        cx.resize(unique(cx.begin(), cx.end()) - cx.begin());

        for (int x : cx) {
            if (af[x] == 0) {
                af[x] = 1;
                f.add(x, +1);
            }
        }

        int all = f.get(nx - 1);
        ans += 1LL * all * (all + 1) / 2;

        cx.insert(cx.begin(), -1);
        cx.push_back(nx);
        for (int j = 1; j < (int)cx.size(); j++) {
            int cnt = f.get(cx[j - 1] + 1, cx[j] - 1);
            ans -= 1LL * cnt * (cnt + 1) / 2;
        }
    }
    return ans;
}


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
        cout << solve(a) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}