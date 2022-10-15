#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>
#include <random>
#include <chrono>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;


void solve() {
    int n, m;
    cin >> n >> m;
    int mm = max(m, n);
    vector<vector<int> > a(n, vector<int> (mm));
    vector<int> c(mm, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            c[j] = max(c[j], a[i][j]);
        }
    }
    m = mm;
    vector<pii> p(m);
    for (int i = 0; i < m; ++i) {
        p[i] = pii(c[i], i);
    }
    sort(p.rbegin(), p.rend());
    vector<vector<int> > b(2 * n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[j][i] = b[j + n][i] = a[j][p[i].second];
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += p[i].first;
    }
    int up = 1 << n;
    vector<vector<int> > g(up);
    for (int i = 0; i < up; ++i) {
        for (int j = 0; j < up; ++j) {
            if ((i | j) == j)
                g[i].push_back(j);
        }
    }
    vector<vector<int> > d(n + 1, vector<int>(up, 0));
    vector<vector<int> > pl(n, vector<int> (up, 0));
    for (int i = 0; i < n; ++i) {
        for (int pos = 0; pos < up; ++pos) {
            for (int sh = 0; sh < n; ++sh) {
                int cur = 0;
                for (int j = 0; j < n; ++j) {
                    if ((pos >> j) & 1) {
                        cur += b[sh + j][i];
                    }
                }
                pl[i][pos] = max(pl[i][pos], cur);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int pos1 = 0; pos1 < up; ++pos1) {
            for (int id = 0; id < g[pos1].size(); ++id) {
                int pos2 = g[pos1][id];
                int v = d[i][pos1];
                int add = pl[i][pos2 - pos1];
                d[i + 1][pos2] = max(d[i + 1][pos2], v + add);
                res = max(res, d[i + 1][pos2]);
            }
        }
    }
    cout << res << endl;
    return;
    /*p.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            p.push_back(pii(b[i][j], j));
        }
    }
    sort(p.rbegin(), p.rend());
    c.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        ++c[p[i].second];
    }
    
    
    vector<int> intr;
    for (int i = 0; i < n; ++i) {
        if (c[i] > 1)
            intr.push_back(i);
    }
    vector<int> add;
    for (int i = 0; i < n; ++i) {
        if (c[p[i].second] <= 1)
            add.push_back(p[i].first);
    }
    sort(add.rbegin(), add.rend());
    while (add.size() < n)
        add.push_back(0);
    int sz = intr.size();
    if (sz == 0) {
        cout << res << endl;
        return;
    }
    vector<vector<int> > d(2 * n, vector<int>(sz));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz; ++j) {
            d[i][j] = d[i + n][j] = b[i][intr[j]];
        }
    }
    
    ll up = 1;
    for (int i = 1; i < sz; ++i) {
        up *= n;
    }
    vector<int> mx(n);
    for (ll msk = 0; msk < up; ++msk) {
        int cur = 0;
        for (int i = 0; i < n; ++i)
            mx[i] = d[i][0];
        ll curMsk = msk;
        for (int j = 1; j < sz; ++j) {
            int r = curMsk % n;
            curMsk /= n;
            for (int i = 0; i < n; ++i) {
                mx[i] = max(mx[i], d[i + r][j]);
            }
        }
        sort(mx.rbegin(), mx.rend());
        int i1 = 0, i2 = 0;
        for (int i = 0; i < n; ++i) {
            if (mx[i1] > add[i2]) {
                cur += mx[i1];
                ++i1;
            }
            else {
                cur += add[i2];
                ++i2;
            }
        }
        res = max(res, cur);
    }
    cout << res << endl;*/

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) 
        solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}