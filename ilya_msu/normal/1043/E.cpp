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

bool comp(const pair<pii, int>& p1, pair<pii, int>& p2) {
    return (p1.first.first - p1.first.second < p2.first.first - p2.first.second) || 
        ((p1.first.first - p1.first.second == p2.first.first - p2.first.second) && (p1.second < p2.second));
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<pii, int> > p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;
    }
    sort(p.begin(), p.end(), comp);
    vector<ll> pr(n + 1);
    pr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pr[i] = pr[i - 1] + p[i - 1].first.first;
    }
    vector<ll> suf(n + 1);
    suf[0] = 0;
    for (int i = 1; i <= n; ++i) {
        suf[i] = suf[i - 1] + p[n - i].first.second;
    }
    vector<ll> res(n);
    for (ll k = 0; k < n; ++k) {
        int id = p[k].second;
        res[id] = k * p[k].first.second + (n - 1 - k) * p[k].first.first + pr[k] + suf[n - 1 - k];
    }
    vector<int> idx(n);
    for (int i = 0; i < n; ++i) {
        idx[p[i].second] = i;
    }
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        int id1 = idx[u], id2 = idx[v];
        ll cur = min(p[id1].first.first + p[id2].first.second, p[id1].first.second + p[id2].first.first);
        res[u] -= cur;
        res[v] -= cur;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
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