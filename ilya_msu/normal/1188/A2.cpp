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

vector<vector<pll> > g;
vector<int> leave;

void dfs(int pos, int pr = -1) {
    int to = -1;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i].first == pr)
            continue;
        to = g[pos][i].first;
        break;
    }
    if (to == -1) {
        leave[pos] = pos;
        return;
    }
    int tot = to;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i].first == pr)
            continue;
        to = g[pos][i].first;
        dfs(to, pos);
    }
    leave[pos] = leave[tot];
}

vector<pii> res1;
vector<ll> res2;

void dfs2(int pos, ll add, int leaf, int pr = -1) {
    //cerr << pos << " " << add << endl;
    vector<int> l;
    vector<ll> c;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i].first;
        if (to == pr)
            continue;
        l.push_back(to);
        c.push_back(g[pos][i].second);
    }
    if (c.empty())
        return;
    c[0] -= add;
    if (c.size() == 2) {
        //cerr << c[0] << " " << c[1] << endl;
        ll x = (c[0] - c[1]) / 2;
        res1.push_back(pii(leave[l[0]], leaf));
        res2.push_back(x);
        res1.push_back(pii(leave[l[1]], leaf));
        res2.push_back(-x);
        ll y = c[0] - x;
        res1.push_back(pii(leave[l[0]], leave[l[1]]));
        res2.push_back(y);
    }
    else {
        ll c0 = c[0];
        for (int i = 3; i < l.size(); ++i) {
            res1.push_back(pii(leave[l[0]], leave[l[i]]));
            res2.push_back(c[i]);
            c0 -= c[i];
        }
        ll d0 = (c0 + c[1] - c[2]) / 2;
        res1.push_back(pii(leave[l[0]], leave[l[1]]));
        res2.push_back(d0);
        ll d1 = (c0 + c[2] - c[1]) / 2;
        res1.push_back(pii(leave[l[0]], leave[l[2]]));
        res2.push_back(d1);
        ll d2 = (c[1] + c[2] - c0) / 2;
        res1.push_back(pii(leave[l[1]], leave[l[2]]));
        res2.push_back(d2);
    }
    dfs2(l[0], c[0] + add, leave[l[1]], pos);
    for (int i = 1; i < l.size(); ++i) {
        dfs2(l[i], c[i], leave[l[0]], pos);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> d(n, 0);
    g.resize(n);
    ll a, b, c;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        ++d[a];
        ++d[b];
        g[a].push_back(pii(b, c));
        g[b].push_back(pii(a, c));
    }
    for (int i = 0; i < n; ++i) {
        if (d[i] == 2) {
            cout << "NO\n";
            return;
        }
    }
    if (n == 2) {
        cout << "YES\n";
        cout << 1 << endl;
        cout << 1 << " " << 2 << " " << g[0][0].second << endl;
        return;
    }
    int st = 0;
    while (d[st] == 1)
        ++st;
    leave.resize(n);
    dfs(st, -1);
    dfs2(st, 0, -1, -1);
    cout << "YES\n";
    cout << res1.size() << endl;
    for (int i = 0; i < res1.size(); ++i) {
        cout << res1[i].first  + 1 << " " << res1[i].second + 1 << " " << res2[i] << "\n";
    }


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