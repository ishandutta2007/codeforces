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
const ll mod = 998244353;//1000 * 1000 * 1000 + 7;

vector<int> sz, d;
vector<vector<int> > g;

void dfs(int pos, int p) {
    sz[pos] = 1;
    for (int to : g[pos]) {
        if (to == p)
            continue;
        d[to] = d[pos] + 1;
        dfs(to, pos);
        sz[pos] += sz[to];
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    g.resize(n);
    int u, v;
    for (int i = 0; i + 1 < n; ++i) {
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d.assign(n, 0);
    sz.assign(n, 0);
    dfs(0, -1);
    vector<int>res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = sz[i] - d[i] - 1;
    }
    sort(res.rbegin(), res.rend());
    ll ans = 0;
    for (int i = 0; i < n - k; ++i) {
        ans += res[i];
    }
    cout << ans << endl;


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