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

vector<int> dp;
vector<vector<int> > g;

void dfs(int pos, int p = -1) {
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to != p) {
            dp[to] = dp[pos] + 1;
            dfs(to, pos);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> d(n, 0);
    g.assign(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ++d[a];
        ++d[b];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dp.assign(n, 0);
    int st = 0;
    while (d[st] == 1)
        ++st;
    dfs(st);
    int res = -1;
    for (int i = 0; i < n; ++i) {
        if (d[i] != 1) {
            ++res;
            int add = 0;
            for (int j = 0; j < g[i].size(); ++j) {
                if (d[g[i][j]] == 1)
                    add = 1;
            }
            res += add;
        }
    }
    int x1 = 0, x2 = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] == 1) {
            if (dp[i] & 1)
                x1 = 1;
            else 
                x2 = 1;
        }
    }
    int res1 = 1;
    if (x1 * x2)
        res1+=2;
    cout << res1 << " " << res << endl;

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