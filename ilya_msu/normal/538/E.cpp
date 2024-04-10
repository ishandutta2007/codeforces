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
const ll N = 1001;
//const int M = 10000000;
int n;
vector<vector<int> > g;
vector<int> h;
vector<int> maxPen, minPen;
vector<int> leafs;
vector<int> sz;
vector<int> children;

void dfs0(int pos, int pr = -1) {
    if (pr != -1)
        h[pos] = h[pr] + 1;
    sz[pos] = 1;
    if ((g[pos].size() == 1) && (pr != -1))
        leafs[pos] = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == pr)
            continue;
        ++children[pos];
        dfs0(to, pos);
        leafs[pos] += leafs[to];
        sz[pos] += sz[to];
    }
}

void dfs1(int pos, int pr = -1) {
    if ((h[pos] & 1) == 0) {
        maxPen[pos] = sz[pos] - 1;
    }
    else {
        maxPen[pos] = max(0, children[pos] - 1);
    }
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == pr)
            continue;
        dfs1(to, pos);
        if ((h[pos] & 1) == 0) {
            maxPen[pos] = min(maxPen[pos], maxPen[to]);
        }
        else {
            maxPen[pos] += maxPen[to];
        }
    }
}

void dfs2(int pos, int pr = -1) {
    if ((h[pos] & 1) == 1) {
        minPen[pos] = sz[pos] - 1;
    }
    else {
        minPen[pos] = max(0, children[pos] - 1);
    }
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == pr)
            continue;
        dfs2(to, pos);
        if ((h[pos] & 1) == 1) {
            minPen[pos] = min(minPen[pos], minPen[to]);
        }
        else {
            minPen[pos] += minPen[to];
        }
    }
}

void solve() {
    cin >> n;
    g.resize(n);
    h.assign(n, 0);
    maxPen.assign(n, 0);
    minPen.assign(n, 0);
    leafs.assign(n, 0);
    sz.assign(n, 0);
    children.assign(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs0(0);
    dfs1(0);
    dfs2(0);
    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    cout << leafs[0] - maxPen[0] << " " << minPen[0] + 1 << endl;    
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