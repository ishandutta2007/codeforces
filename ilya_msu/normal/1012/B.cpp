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

vector<vector<int> > g;
vector<int> used;

void dfs(int pos) {
    used[pos] = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (used[to])
            continue;
        dfs(to);
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    g.resize(m + n);
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        y += n;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int res = 0;
    used.assign(m + n, 0);
    for (int i = 0; i < m + n; ++i) {
        if (used[i])
            continue;
        dfs(i);
        ++res;
    }
    cout << res - 1 << endl;
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