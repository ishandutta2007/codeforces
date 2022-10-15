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
const ll mod = 1000 * 1000 * 1000 + 7;


vector<vector<int> > g;
vector<vector<int> > d;
vector<vector<int> > mp;

void dfs0(int st, int pos, int pr) {
    if (pr != -1)
        d[st][pos] = d[st][pr] + 1;
    for (auto to:g[pos]) {
        if (to == pr)
            continue;
        dfs0(st, to, pos);
    }
}

int dfs(int pos, int pr) {
    int res = 1;
    for (int to:g[pos]) {
        if (to == pr)
            continue;
        int cur = dfs(to, pos);
        mp[pos][to] = cur;
        mp[to][pos] = g.size() - cur;
        res += cur;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    g.resize(n);
    int x, y;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    d.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        dfs0(i, i, -1);
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d[i][j] <<  " ";
        }
        cout << endl;
    }*/
    vector<vector<ll> > a(n, vector<ll>(n, 0));
    mp.assign(n, vector<int>(n, 0));
    dfs(0, -1);

    vector<vector<pii> > q(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            q[d[i][j]].push_back({i, j});
        }
    }

    for (int i = 0; i < q.size(); ++i) {
        //cerr << i << endl;
        for (pii p:q[i]) {
            int x = p.first, y = p.second;
            int mid = -1;
            if (x != y) {
                for (int to:g[x]) {
                    if (d[to][y] == d[x][y] - 1)
                        mid = to;
                }
                if (mid == -1) {
                    cerr << "FAIL\n";
                    return;
                }
            }
            for (int to:g[y]) {
                if (d[x][to] == d[x][y] + 1) {
                    ll add = mp[y][to];
                    if (x == y) {
                        add *= (n - add);
                    }
                    else {
                        add *= mp[mid][x];
                    }
                    a[x][to] = max(a[x][to], a[x][y] + add);
                    a[to][x] = a[x][to];
                }
            }
        }
    }
    /*cout << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] <<  " ";
        }
        cout << endl;
    }*/
    ll res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res = max(res, a[i][j]);
    cout << res << endl;

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