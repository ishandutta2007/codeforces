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
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000 * 1000 + 5;

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > g(2 * n), invg(2 * n);
    vector<int> din(2 * n), dout(2 * n);
    int loops = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (x == y)
            ++loops;
        g[x].push_back(y);
        invg[y].push_back(x);
        ++dout[x];
        ++din[y];
    }
    vector<int> used(n * 2, 0);
    ll res = 1;
    for (int i = 0; i < 2 * n; ++i) {
        if (used[i])
            continue;
        if (dout[i] == 0) {
            ll m = 0;
            used[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                ++m;
                for (int j = 0; j < invg[v].size(); ++j) {
                    used[invg[v][j]] = 1;
                    q.push(invg[v][j]);
                }
            }
            res = (res * m) % mod;
        }
    }
    int cycles = -loops;
    for (int i = 0; i < 2 * n; ++i) {
        if (used[i])
            continue;
        ++cycles;
        used[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int j = 0; j < invg[v].size(); ++j) {
                if (used[invg[v][j]])
                    continue;
                used[invg[v][j]] = 1;
                q.push(invg[v][j]);
            }
            for (int j = 0; j < g[v].size(); ++j) {
                if (used[g[v][j]])
                    continue;
                used[g[v][j]] = 1;
                q.push(g[v][j]);
            }
        }
    }
    for (int i = 0; i < cycles; ++i)
        res = (res + res) % mod;
    cout << res << endl;
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