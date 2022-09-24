// ILDAR LUCHIY
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

void print(vector<pair<int, int>> a) {
    if (a.empty()) printf("-1\n");
    else for (auto o : a) printf("%d %d\n", o.first, o.second);
}

vector<int> gen(int n) {
    if (n == 1) return vector<int>(1, 1);

    vector<int> res;
    int l = n / 2 + 1;
    int r = n / 2 + 1;
    res.push_back(l);
    for (int i = 0; i < n - 1; i++) {
        if (!(((i % 2) ^ n) & 1)) {
            res.push_back(--l);
        } else {
            res.push_back(++r);
        }
    }
    for (int i = 0; i < n; i++) assert(1 <= res[i] && res[i] <= n);
    assert(res.back() == 1);
//    reverse(res.begin(), res.end());
    return res;
}

vector<pair<int, int>> solve(int n, int m) {
    vector<pair<int, int>> res;

    /*auto y = gen(m);
    auto x = gen(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res.push_back({x[i], y[j]});
        }
    }
    res.pop_back();
    res.insert(res.begin(), {1, 1});*/

    /*if (n == 1) {
//        res = gen(m);
        auto cres = gen(m);
        for (int i = 0; i < m; i++) res.push_back({1, cres[i]});
    } else {
        auto cres = solve((n + 1) / 2, m);
        bool f = 0;
        for (auto o : cres) {
            if (f) {
                o.first = n + 1 - o.first;
                o.second = m + 1 - o.second;
            }

            res.push_back(o);
            if (o.first * 2 - 1 != n) {
                res.push_back({n + 1 - o.first, m + 1 - o.second});
                f ^= 1;
            }
        }
    }*/
    /*auto x = gen(n), y = gen(m);
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res.push_back({x[k % n], y[(i + k) % m]});
            k++;
        }
    }*/

    int l, r;
    if (n % 2 == 1) {
        auto v = gen(m);
        for (int x : v) res.push_back({(n + 1) / 2, x});
        l = (n + 1) / 2 - 1;
        r = (n + 1) / 2 + 1;
    } else {
        l = n / 2;
        r = n / 2 + 1;
    }
    for (int t = 0; t < n / 2; t++) {
        for(int i = m; i >= 1; i--) {
            res.push_back({r, m + 1 - i});
            res.push_back({l, i});
        }
        l--;
        r++;
    }
//    res.pop_back();
//    res.insert(res.begin(),{1, 1});
    reverse(res.begin(), res.end());

    for (auto o : res) {
        db2(o.first, o.second);
    }
    db3(n, m, res.size());
    assert((int)res.size() == n * m);
    for (int i = 0; i < (int)res.size(); i++) {
        assert(1 <= res[i].first && res[i].first <= n);
        assert(1 <= res[i].second && res[i].second <= m);
    }
    vector<vector<char>> was(n + 1, vector<char>(m +1));
    for (auto o : res) {
        assert(!was[o.first][o.second]);
        was[o.first][o.second] = 1;
    }
    vector<pair<int, int>> d;
    for (int i = 1; i < (int)res.size(); i++) {
        d.push_back({res[i].first - res[i -1 ].first, res[i].second - res[i -1 ].second});
    }
    sort(d.begin(), d.end());
    for (int i = 1; i < (int)d.size(); i++) assert(d[i] != d[i - 1]);

    return res;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

//    for (int n = 1; n <= 30; n += 1) for (int m = 1; m <= 30; m += 1) {
//        db2(n, m);
//        solve(n, m);
//    }

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        print(solve(n, m));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}