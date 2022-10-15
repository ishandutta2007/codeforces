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

vector<int> degs, used;
vector<vector<pii> > g;
vector<int> res;
vector<int> d;

int dfs(int pos) {
    used[pos] = 1;
    int sum = (d[pos] == 1);
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i].first;
        if (used[to])
            continue;
        int cur = dfs(to);
        if (cur & 1)
            res.push_back(g[pos][i].second);
        sum += cur;
    }
    return sum;
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    d.resize(n);
    int minusOne = -1;
    int ones = 0;
    int st = -1;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        if (d[i] == -1)
            minusOne = i;
        if (d[i] == 1)
            ++ones;
        if (d[i] == 1)
            st = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(pii(b, i));
        g[b].push_back(pii(a, i));
    }
    if ((minusOne == -1) && (ones & 1)) {
        cout << -1 << endl;
        return;
    }
    if (st == -1) {
        cout << 0 << endl;
        return;
    }
    if (ones & 1)
        d[minusOne] = 1;
    degs.assign(n, 0);
    used.assign(n, 0);
    dfs(st);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] + 1 << "\n";
    }
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