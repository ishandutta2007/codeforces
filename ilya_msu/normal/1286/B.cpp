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
const ll N = 100000 + 10;

vector<vector<int> > g;
vector<int> a, c;
bool ok;

int dfs(int pos, int p, int m) {
    int sz = 0;
    for (int to : g[pos]) {
        if (to == p) {
            continue;
        }
        int add = dfs(to, pos, sz + m);
        sz += add;
    }
    if (sz < c[pos]) {
        ok = 0;
        return sz + 1;
    }
    for (int i = 0; i < a.size(); ++i) {
        if ((a[i] >= m) && (a[i] < m + sz)) {
            if (a[i] - m >= c[pos]) {
                ++a[i];
            }
        }
    }
    a[pos] = m + c[pos];
    return sz + 1;
}

void solve() {
    int n;
    cin >> n;
    g.resize(n);
    a.assign(n, n + 5);
    c.resize(n);
    int p;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p >> c[i];
        --p;
        if (p == -1)
            r = i;
        else {
            g[p].push_back(i);
            g[i].push_back(p);
        }
    }
    ok = 1;
    dfs(r, -1, 1);
    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO\n";
    }
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
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