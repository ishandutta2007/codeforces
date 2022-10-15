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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii> > g(n);
    vector<ll> len(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b >> len[i];
        --a, --b;
        g[a].push_back(pii(b, i));
        g[b].push_back(pii(a, i));
    }
    priority_queue<pair<ll, pii> > q;
    q.push(make_pair(0, pii(0, -1)));
    vector<ll> d(n, -1);
    vector<int> used(n, 0);
    d[0] = 0;
    int e = 0;
    cout << min(n - 1, k) << endl;
    while ((!q.empty()) && (e < k)) {
        pii vv = q.top().second;
        q.pop();
        int v = vv.first;
        if (used[v])
            continue;
        used[v] = 1;
        if (v != 0) {
            cout << vv.second + 1 << " ";
            ++e;
        }
        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i].first;
            int ed = g[v][i].second;
            if ((d[to] == -1) || (d[to] > d[v] + len[ed])) {
                d[to] = d[v] + len[ed];
                q.push(make_pair(-d[to], pii(to, ed)));
            }
        }
    }
    cout << endl;

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