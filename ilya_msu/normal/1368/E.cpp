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
#include<unordered_map>
#include<deque>
#include<cmath>





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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;


vector<vector<int> > g, rg;

vector<int> d;


int comp(int pos) {
    if (g[pos].empty()) {
        d[pos] = 0;
        return d[pos];
    }
    if (d[pos] != -1)
        return d[pos];
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        d[pos] = max(d[pos], comp(to));
    }
    ++d[pos];
    return d[pos];
}


void solve() {
    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    rg.assign(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }
    vector<int> p1(n), p2(n), p3(n);
    for (int i = 0; i < n; ++i) {
        for (auto to1 : g[i]) {
            ++p1[to1];
            for (auto to2:g[to1]) {
                ++p2[to2];
                for (auto to3:g[to2]) {
                    ++p3[to3];
                }
            }
        }
    }
    vector<int> q, qq;
    for (int i = 0; i < n; ++i) {
        if ((p3[i] == 0) && (p2[i] > 0)) {
            q.push_back(i);
        }
    }
    vector<int> cl;
    while (!q.empty()) {
        for (int i = 0; i < q.size(); ++i) {
            int v = q[i];
            //cerr << v << endl;
            cl.push_back(v);
            for (auto to1 : g[v]) {
                --p1[to1];
                p2[to1] -= p1[v];
                p3[to1] -= p2[v];
                if ((p3[to1] == 0) && (p2[v] > 0)) {
                    qq.push_back(to1);
                    //cerr << "to1=" << to1 << endl;
                }
                for (auto to2:g[to1]) {
                    --p2[to2];
                    p3[to2] -= p1[v];
                    if ((p3[to2] == 0) && (p1[v] > 0)) {
                            qq.push_back(to2);
                            //cerr << "to2=" << to2 << endl;

                        }
                    for (auto to3:g[to2]) {
                        --p3[to3];
                        if (p3[to3] == 0) {
                            qq.push_back(to3);
                            //cerr << "to3=" << to3 << endl;

                        }
                    }
                }
            }
        }
        q.resize(0);
        for (int i = 0; i < qq.size(); ++i) {
            int v = qq[i];
            if ((p3[v] == 0) && (p2[v] > 0)) {
                q.push_back(v);
            }
        }
        qq.resize(0);
    }

    cout << cl.size() << "\n";
    for (int i = 0; i < cl.size(); ++i) {
        cout << cl[i] + 1 << " ";
    }
    cout << "\n";

    /*



    d.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (d[i] == -1)
            comp(i);
    }
    vector<pii> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = pii(d[i], i);
    }
    sort(p.rbegin(), p.rend());
    vector<int> used(n, 0);
    vector<int> cl(n, 0);
    for (int i = 0; i < n; ++i) {
        int ind = p[i].second;
        //cerr << ind << endl;
        if (used[ind]) {
            continue;
        }
        used[ind] = 1;
        bool bad = 0;
        int id = 0;
        for (int i1 = 0; i1 < g[ind].size(); ++i1) {
            int to = g[ind][i1];
            for (int i2 = 0; i2 < g[to].size(); ++i2) {
                int toto = g[to][i2];
                for (int i3 = 0; i3 < g[ind].size(); ++i3) {
                    if (toto == g[ind][i3]) {
                        bad = 1;
                        id = toto;
                    }
                }
            }
        }
        //cerr << bad << endl;
        if (bad) {
            for (auto to:g[ind]) {
                if (to == id)
                    continue;
                used[to] = 1;
                for (auto toto : g[to]) {
                    used[toto] = 1;
                    cl[toto] = 1;
                }
            }
            continue;
        }
        for (auto to:g[ind]) {
            used[to] = 1;
            for (auto toto : g[to]) {
                used[toto] = 1;
                cl[toto] = 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
        res += cl[i];
    cout << res << "\n";
    for (int i = 0; i < n; ++i) {
        if (cl[i])
            cout << i + 1 << " ";
    }
    cout << "\n";*/


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
    for (int tt = 0; tt < t; ++tt)
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}