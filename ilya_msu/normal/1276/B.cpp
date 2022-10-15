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
vector<int> used;

int dfs(int pos) {
    used[pos] = 1;
    int res = 1;
    for (int to:g[pos]) {
        if (used[to])
            continue;
        res += dfs(to);
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n);
    int a, b;
    cin >> a >> b;
    --a, --b;
    int e1, e2;

    for (int i = 0; i < m; ++i) {
        cin >> e1 >> e2;
        --e1, --e2;
        g[e1].push_back(e2);
        g[e2].push_back(e1);
    }
    used.assign(n, 0);
    ll a1 = dfs(a);
    used.assign(n, 0);
    ll b1 = dfs(b);
    used.assign(n, 0);
    used[b] = 1;
    ll a2 = dfs(a) + 1;
    used.assign(n, 0);
    used[a] = 1;
    ll b2 = dfs(b) + 1;
    //cerr << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
    cout << (a1 - a2) * (b1 - b2) << "\n";
    

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