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
//#include<unordered_map>




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
const ll N = 5000 + 100;
//const int M = 10000000;
int n, m;
vector<pii> ed;
vector<vector<int> > g;
vector<int> used;
vector<int> order;

void dfs(int pos) {
    used[pos] = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (used[to])
            continue;
        dfs(to);
    }
    order.push_back(pos);
}

bool f(int x) {
    g.clear();
    g.resize(n);
    for (int i = 0; i < x; ++i) {
        g[ed[i].first].push_back(ed[i].second);
    }
    used.assign(n, 0);
    order.clear();
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs(i);
    }
    for (int i = 1; i < n; ++i) {
        int v = order[i];
        bool ok = 0;
        for (int j = 0; j < g[v].size(); ++j) {
            if (g[v][j] == order[i - 1]) {
                ok = 1;
                break;
            }
        }
        if (!ok)
            return 0;
    }


    return 1;
}

void solve() {
    cin >> n >> m;
    ed.resize(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ed[i] = pii(b, a);
    }
    if (!f(m)) {
        cout << -1 << endl;
        return;
    }
    int low = 0, up = m;
    while (up - low > 1) {
        int mid = (up + low) / 2;
        if (f(mid)) {
            up = mid;
        }
        else
            low = mid;
    }
    cout << up << endl;
    
}





//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
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