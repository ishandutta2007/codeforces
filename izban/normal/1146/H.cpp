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

const int INF = 1e9;


namespace dbl_utils {
    typedef double dbl;

    const dbl EPS = 1e-9;

    bool eq(dbl a, dbl b) {
        return fabs(a - b) < EPS;
    }

    bool ne(dbl a, dbl b) {
        return !eq(a, b);
    }

    bool lt(dbl a, dbl b) {
        return a < b && !eq(a, b);
    }

    bool le(dbl a, dbl b) {
        return !lt(b, a);
    }

    bool ge(dbl a, dbl b) {
        return !lt(b, a);
    }

    bool gt(dbl a, dbl b) {
        return lt(b, a);
    }

    int sign(dbl x) {
        if (eq(x, 0)) return 0;
        if (x > 0) return 1;
        return -1;
    }
}
using namespace dbl_utils;

template <typename T>
struct _pt {
    T x, y;

    _pt<T>() {}
    _pt<T>(T _x, T _y) : x(_x), y(_y) {}

    _pt<T> operator+ (const _pt<T> &p) const {
        return _pt<T>(x + p.x, y + p.y);
    }

    _pt<T>& operator+= (const _pt<T> &p) {
        return *this = *this + p;
    }

    _pt<T> operator- (const _pt<T> &p) const {
        return _pt<T>(x - p.x, y - p.y);
    }

    _pt<T>& operator-= (const _pt<T> &p) {
        return *this = *this - p;
    }

    _pt<T> operator* (T d) const {
        return _pt<T>(x * d, y * d);
    }

    _pt<T>& operator*= (T d) {
        return *this = *this * d;
    }

    T operator* (const _pt<T> &p) const {
        return x * p.y - y * p.x;
    }

    T operator% (const _pt<T> &p) const {
        return x * p.x + y * p.y;
    }

    T d2() const {
        return *this % *this;
    }

    dbl d() const {
        return sqrt((dbl)d2());
    }

    dbl ang() const {
        return atan2((dbl)y, (dbl)x);
    }

    _pt<T> rotate90() const {
        return _pt<T>(-y, x);
    }

    _pt<T> rotate(dbl ang) {
        return _pt<T>(x * cos(ang) - y * sin(ang),
                      x * sin(ang) + y * cos(ang));
    }

    int turn(const _pt<T> &p) const {
        return sign((*this) * p);
    }

    bool operator< (const _pt<T> &p) const {
        if (!eq(x, p.x)) return lt(x, p.x);
        return lt(y, p.y);
    }

    bool operator== (const _pt<T> &p) const {
        return eq(x, p.x) && eq(y, p.y);
    }

    void read() {
        cin >> x >> y;
    }
};
typedef _pt<long long> pt;

const int N = 303;
ll dp[3][N][N];

ll solve(vector<pt> a) {
    int n = a.size();
    sort(a.begin(), a.end());

    vector<vector<vector<int>>> ok(n, vector<vector<int>>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if ((a[j] - a[i]) * (a[k] - a[j]) > 0) {
                    ok[i][j].push_back(k);
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {

        vector<pair<pt, int>> bb;
        for (int j = i + 1; j < n; j++) {
            bb.push_back({a[j] - a[i], j});
        }
        sort(bb.begin(), bb.end(), [&](const pair<pt, int> &p1, const pair<pt, int> &p2) {
            return p1.first * p2.first > 0;
        });
        vector<pt> b;
        for (auto o : bb) b.push_back(o.first);
        int m = b.size();

        vector<int> rid(n, -1);
        for (int i = 0; i < m; i++) rid[bb[i].second] = i;

        const int K = 3;
        memset(dp, 0, sizeof(dp));
//        vector<vector<vector<ll>>> dp(K, vector<vector<ll>>(m, vector<ll>(m)));
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                dp[0][i][j]++;
                for (int kk : ok[bb[i].second][bb[j].second]) {
                    int k = rid[kk];
                    if (k <= j) continue;
                    if (1) {
//                for (int k = j + 1; k < m; k++) {
//                    if ((b[j] - b[i]) * (b[k] - b[j]) > 0) {
                        for (int t = 0; t < K - 1; t++) {
                            dp[t + 1][j][k] += dp[t][i][j];
                        }
                    }
                }
                ans += dp[K - 1][i][j];
            }
        }
    }
    return ans;
}

void test() {
    int n = 300;
    vector<pt> a(n);
    mt19937 rnd;
    for (int i = 0; i < n; i++) {
        a[i].x = rnd() % (int)1e6;
        a[i].y = rnd() % (int)1e6;
    }
    cout << solve(a) << endl;
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    exit(0);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    test();

    int n;
    while (cin >> n) {
        vector<pt> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
        }
        cout << solve(a) << endl;

    }


#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}