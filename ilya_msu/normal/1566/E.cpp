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
#include<iterator>
#include<random>





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
const ll mod = 998244353;

int n;
vector<vector<int> > g;
vector<int> d;
int res;

void dfs(int pos, int p) {
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        dfs(to, pos);
    }
    int l = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        if (d[to] > 0)
            l = 0;
    }
    if (l == 1) {
        d[pos] = 1;
        return;
    }
    d[pos] = 0;
    return;
}

void solve() {
    cin >> n;
    g.clear();
    g.resize(n);  
    d.assign(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    res = 0;
    dfs(0, -1);
    for (int i = 1; i < n; ++i)
        res += 2 * d[i] - 1;
    res += d[0];
    cout << res << endl;

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