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
const ll mod = 998244353;

vector<vector<int> > g;
vector<int> d;

void dfs(int pos, int p = -1) {
    for (int to:g[pos]) {
        if (to == p)
            continue;
        d[to] = d[pos] + 1;
        dfs(to, pos);
    }
}

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    --a, --b;
    g.assign(n, vector<int>());
    int x, y;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    d.assign(n, 0);
    dfs(a);
    if (d[b] <= da) {
        cout << "Alice\n";
        return;
    }
    int id = a;
    for (int i = 0; i < n; ++i) {
        if (d[i] > d[id])
            id = i;
    }
    d[id] = 0;
    dfs(id);
    int diam = 0;
    for (int i = 0; i < n; ++i)
        diam = max(diam, d[i]);
    if ((diam >= 2 * da + 1) && (db >= 2 * da + 1)) 
        cout << "Bob\n";
    else 
        cout << "Alice\n";


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