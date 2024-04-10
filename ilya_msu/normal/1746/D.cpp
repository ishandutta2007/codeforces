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
#include<unordered_set>
#include<chrono>
#include<random>
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
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 998244353;

vector<vector<int> > g;
vector<ll> s;
map<pair<int, ll>, ll> res;

ll dfs(int pos, ll k, int p = -1) {
    auto it = res.find(make_pair(pos, k));
    if (it != res.end())
        return it->second;
    int d = g[pos].size() - (int)(pos > 0);
    ll ans = s[pos] * k;
    if (d == 0) {
        return ans;
    }
    int q = k / d;
    int r = k % d;
    vector<ll> r0, r1;
    for (auto x : g[pos]) {
        if (x != p) {
            r0.push_back(dfs(x, q, pos));
            if (r)
                r1.push_back(dfs(x, q + 1, pos) - r0.back());
            ans += r0.back();
        }
    }
    if (r == 0) {
        res[make_pair(pos, k)] = ans;
        return ans;
    }
    sort(r1.rbegin(), r1.rend());
    for (int i = 0; i < r; ++i)
        ans += r1[i];
    res[make_pair(pos, k)] = ans;
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    g.clear();
    res.clear();
    g.assign(n, vector<int>());
    s.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    cout << dfs(0, k) << "\n";

    
        
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}