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

vector<vector<int> > g;
vector<map<ll, ll> > mp;
vector<ll> x;
ll res = 0;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void dfs(int pos, int p) {
    for (auto it = mp[pos].begin(); it != mp[pos].end(); ++it) {
        ll num = it->second % mod;
        res = (res + it->first * num) % mod;
    }
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        for (auto it = mp[pos].begin(); it != mp[pos].end(); ++it) {
            ll num = it->second % mod;
            ll g = gcd(x[to], it->first);
            if (mp[to].find(g) == mp[to].end())
                mp[to][g] = num;
            else {
                mp[to][g] += num;
            }
        }
        dfs(to, pos);
    }
}


void solve() {
    int n;
    cin >> n;
    x.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    int a, b;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    mp.resize(n);
    for (int i = 0; i < n; ++i) {
        mp[i][x[i]] = 1;
    }
    dfs(0, -1);
    cout << res << endl;
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}