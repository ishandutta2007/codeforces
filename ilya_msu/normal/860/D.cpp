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
const int N = 1000 * 1000 + 5;

vector<vector<int> > ans(3);
set<pii> ed;
vector<vector<int> > g, g0;
vector<int> unusedTo;

vector<int> used;

void dfs1(int pos) {
    used[pos] = 1;
    for (int i = 0; i < g0[pos].size(); ++i) {
        int to = g0[pos][i];
        if (used[to]) {
            pii pr(pos, to);
            if (pr.first > pr.second)
                swap(pr.first, pr.second);
            if (ed.find(pr) != ed.end())
                continue;
            ed.insert(pr);
            if (unusedTo[pos] == -1) {
                unusedTo[pos] = to;
            }
            else {
                ans[0].push_back(unusedTo[pos]);
                ans[1].push_back(pos);
                ans[2].push_back(to);
                unusedTo[pos] = -1;
            }
            continue;
        }
        pii pr(pos, to);
        if (pr.first > pr.second)
            swap(pr.first, pr.second);
        ed.insert(pr);
        g[pos].push_back(to);
        g[to].push_back(pos);
        dfs1(to);
    }
}

pii dfs2(int pos) {
    used[pos] = 1;
    int one = unusedTo[pos];
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (used[to])
            continue;
        pii res = dfs2(to);
        if (res.first != res.second) {
            ans[0].push_back(res.second);
            ans[1].push_back(res.first);
            ans[2].push_back(pos);
            continue;
        }
        if (one == -1) {
            one = res.first;
        }
        else {
            ans[0].push_back(one);
            ans[1].push_back(pos);
            ans[2].push_back(res.first);
            one = -1;
        }
    }
    if (one == -1)
        return pii(pos, pos);
    else
        return pii(pos, one);
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    g0.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g0[a].push_back(b);
        g0[b].push_back(a);
    }
    used.assign(n, 0);
    unusedTo.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    used.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs2(i);
    }
    cout << ans[0].size() << endl;
    for (int i = 0; i < ans[0].size(); ++i) {
        cout << ans[0][i] + 1 << " " << ans[1][i] + 1 << " " << ans[2][i] + 1 << "\n";
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