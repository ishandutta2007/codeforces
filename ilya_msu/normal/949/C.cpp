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

vector<vector<int> > g, inv;
vector<int> used;
vector<int> order;
vector<int> component;
int num = 0;

void dfs1(int pos) {
    used[pos] = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (used[to])
            continue;
        dfs1(to);
    }
    order.push_back(pos);
}


int dfs2(int pos) {
    used[pos] = 1;
    int res = 1;
    for (int i = 0; i < inv[pos].size(); ++i) {
        int to = inv[pos][i];
        if (used[to]) {
            continue;
        }
        res += dfs2(to);
    }
    component[pos] = num;
    return res;
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> u(n);
    for (int i = 0; i < n; ++i)
        cin >> u[i];
    vector<pii> c(m);
    g.resize(n);
    inv.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> c[i].first >> c[i].second;
        --c[i].first, --c[i].second;
        int h1 = u[c[i].first], h2 = u[c[i].second];
        if ((h1 == h2 + 1) || (h1 + h == h2 + 1)) {
            g[c[i].second].push_back(c[i].first);
            inv[c[i].first].push_back(c[i].second);
        }
        if ((h2 == h1 + 1) || (h2 + h == h1 + 1)) {
            g[c[i].first].push_back(c[i].second);
            inv[c[i].second].push_back(c[i].first);
        }
    }
    used.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }
    used.assign(n, 0);
    component.assign(n, -1);
    vector<int> szes;
    for (int i = 0; i < n; ++i) {
        if (!used[order[n - i - 1]]) {
            int cur = dfs2(order[n - i - 1]);
            ++num;
            szes.push_back(cur);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (component[i] != component[g[i][j]])
                szes[component[i]] = INF;
        }
    }
    int id = min_element(szes.begin(), szes.end()) - szes.begin();
    int res = szes[id];
    cout << res << "\n";
    for (int i = 0; i < n; ++i)
        if (component[i] == id)
            cout << i + 1 << " ";
    cout << "\n";
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