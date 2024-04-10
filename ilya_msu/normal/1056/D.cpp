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

int n;
vector<vector<int> > g;
vector<int> d;


int dfs(int pos, int p) {
    d[pos] = 0;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        d[pos] += dfs(to, pos);
    }
    d[pos] = max(d[pos], 1);
    return d[pos];
}

void solve() {
    cin >> n;
    g.resize(n);
    int p;
    for (int i = 1; i < n; ++i) {
        cin >> p;
        --p;
        g[i].push_back(p);
        g[p].push_back(i);

    }
    d.assign(n, 0);
    dfs(0, -1);
    sort(d.begin(), d.end());
    for (int i = 0; i < n; ++i) {
        cout << d[i] << " ";
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