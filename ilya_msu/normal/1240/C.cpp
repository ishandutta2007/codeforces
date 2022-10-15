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
const ll mod = 998244353;

vector<vector<pii> > g;
vector<ll> d1, d2;
vector<ll> add;
ll n, k;

void dfs(int pos, int p) {
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i].first;
        if (to == p) 
            continue;
        dfs(to, pos);
        d2[pos] += d2[to];
    }
    add.clear();
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i].first;
        if (to == p) 
            continue;
        add.push_back(max(g[pos][i].second + d1[to] - d2[to], (ll)0));
    }
    sort(add.rbegin(), add.rend());
    d1[pos] = d2[pos];
    for (int i = 0; i < min(k - 1, (ll)add.size()); ++i) {
        d1[pos] += add[i];
        d2[pos] += add[i];
    }
    if (add.size() >= k) {
        d2[pos] += add[k - 1];
    }
    


}


void solve() {
    cin >> n >> k;
    g.clear();
    g.resize(n);
    int a, b, c;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        g[a].push_back(pii(b, c));
        g[b].push_back(pii(a, c));
    }
    d1.assign(n, 0);
    d2.assign(n, 0);
    add.reserve(n);
    dfs(0, -1);
    cout << max(d1[0], d2[0]) << "\n";

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int q;
cin >> q;
for (int i = 0; i < q; ++i)
        solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}