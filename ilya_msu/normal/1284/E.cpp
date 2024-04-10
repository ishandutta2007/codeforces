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

int getq(pll a) {
    if ((a.first >= 0) && (a.second >= 0))
        return 1;
    if ((a.first >= 0) && (a.second < 0))
        return 0;
    if ((a.first < 0) && (a.second >= 0))
        return 2;
    if ((a.first < 0) && (a.second < 0))
        return -1;
    return 0;
}

bool comp(const pll& a, const pll& b) {
    int q1 = getq(a), q2 = getq(b);
    if (q1 != q2) {
        return (q1 < q2);
    }
    ll d = -a.first * b.second + a.second * b.first;
        return d < 0;
    return 0;

}

void solve() {
    ll n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    ll res = n;
    for (int i = 1; i <= 4; ++i) {
        res = (res * (n - i) / i);
    }
    ll res2 = 0;
    for (int i = 0; i < n; ++i) {
        vector<pll> p;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            p.emplace_back(x[j] - x[i], y[j] - y[i]);
        }
        sort(p.begin(), p.end(), comp);
        for (int j = 0; j < n - 1; ++j) {
            pll f(-p[j].first, -p[j].second);
            int d1 = upper_bound(p.begin(), p.end(), f, comp) - p.begin();
            ll p1, p2;
            if (d1 > j) {
                p1 = d1 - j - 1;
                p2 = n - 2 - p1;
            }
            else {
                p1 = j - d1;
                p2 = n - 2 - p1;
            }
            res2 += p1 * (p1 - 1) * (p1 - 2) / 6;
            res2 += p2 * (p2 - 1) * (p2 - 2) / 6;
        }
    }
    cout << res - res2 / 2 << endl;

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