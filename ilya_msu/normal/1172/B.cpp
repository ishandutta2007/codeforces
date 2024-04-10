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
const ll mod = 998244353;

int n;
vector<vector<int> > g;
vector<int> sz;

ll dfs(int pos, int pr) {
    sz[pos] = 1;
    ll res = 1;
    ll c = 0;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == pr)
            continue;
        ++c;
        res = (((res * dfs(to, pos)) % mod) * c) % mod;
        sz[pos] += sz[to];
    }
    return (res * sz[pos]) % mod;

}

void solve() {
    cin >> n;
    g.resize(n);
    int a, b;
    vector<int> d(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
        ++d[a];
        ++d[b];
    }
    sz.assign(n, 0);
    ll res = n;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= d[i]; ++j) {
            res = (res * j) % mod;

        }
    }
    cout << res << endl;
    //cout << dfs(0, -1) << endl;

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