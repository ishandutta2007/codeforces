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
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000000;

vector<vector<int> > pl;
vector<int> p;
vector<int> d;

void solve() {
    int x0, y0;
    cin >> x0 >> y0;
    int n;
    cin >> n;
    pl.assign(n, vector<int>(n));
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        x[i] -= x0;
        y[i] -= y0;        
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pl[i][j] = 2 * x[i] * x[j] + 2 * y[i] * y[j];
        }
    }
    d.assign(1 << n, -1);
    /*for (int i = 0; i < (1 << 24); ++i) {
        d[i] = -1;
    }*/
    p.resize(1 << n);
    int res = 0;
    int resid = 0;
    //int ind[24];
    d[0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
        if (d[i] == -1)
            continue;
        /*int id = 0;
        for (int j = 0; j < n; ++j) {
            if (!((i >> j) & 1))
                ind[id++] = j;
            if (id < 24)
                ind[id] = -1;
        }*/

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1)
                continue;
            for (int k = j + 1; k < n; ++k) {
                if ((i >> k) & 1)
                    continue;
                int y = d[i] + pl[j][k];
                int xx = i + (1 << j) + (1 << k);
                if (d[xx] < y) {
                    d[xx] = y;
                    p[xx] = i;
                }
            }
        }
        if (d[i] > res) {
            res = d[i];
            resid = i;
        }
    }
    res = -res;
    for (int i = 0; i < n; ++i) {
        res += 2 * x[i] * x[i] + 2 * y[i] * y[i];
    }
    cout << res << endl;
    vector<int> used(n, 0);
    vector<int> ans;
    while (resid != 0) {
        int nid = p[resid];
        for (int i = 0; i < n; ++i) {
            if (((resid ^ nid) >> i) & 1) {
                used[i] = 1;
                ans.push_back(i);
            }
        }
        resid = nid;
    }
    cout << "0 ";
    for (int i = 0; i < ans.size(); i += 2) {
        cout << ans[i] + 1 << " " << ans[i + 1] + 1 << " 0 ";
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            cout << i + 1 << " 0 ";
    }
    cout << endl;
}



//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();




#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}