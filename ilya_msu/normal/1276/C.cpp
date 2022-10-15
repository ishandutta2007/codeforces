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
const ll mod = 1000000007;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> b;
    vector<pll> p;
    int c = 1;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1])
            ++c;
        else {
            b.push_back(c);
            p.push_back(pll(c, a[i - 1]));
            c = 1;
        }
    }
    b.push_back(c);
    p.push_back(pll(c, a[n - 1]));
    sort(b.begin(), b.end());
    ll m = b.size();
    int r = 0;
    ll sm = 0;
    ll res = 0;
    ll ww = 0;
    for (ll w = 1; w <= n; ++w) {
        while ((r < m) && (b[r] <= w)) {
            sm += b[r];
            ++r;
        }
        ll cur = sm + (m - r) * w;
        ll h = cur / w;
        if (h < w)
            continue;
        cur = (cur / w) * w;
        if (cur > res) {
            res = cur;
            ww = w;
        }
    }
    ll hh = res / ww;
    vector<vector<int> > ans(ww, vector<int>(hh, -1));
    int x = 0, y = 0;
    sort(p.rbegin(), p.rend());
    for (int i = 0; i < p.size(); ++i)
        p[i].first = min(p[i].first, ww);
    int id = 0;
    int idd = 0;
    for (int i = 0; i < res; ++i) {
        if (ans[x][y] != -1) {
            x = 0;
            ++idd;
            y = idd;
        }
        ans[x][y] = p[id].second;
        --p[id].first;
        if (p[id].first == 0)
            ++id;
        ++x;
        ++y;
        if (x == ww)
            x = 0;
        if (y == hh)
            y = 0;
    }
    cout << res << "\n" << ww << " " << hh << "\n";
    for (int i = 0; i < ww; ++i) {
        for (int j = 0; j < hh; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }


}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}