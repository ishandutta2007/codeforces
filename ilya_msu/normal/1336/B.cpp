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


ll comp(ll x, ll y, ll z) {
    return 2 * (x * x + y * y + z * z - x * y - x * z - y * z);
}

ll res;

void comp(ll x, ll y, const vector<ll>& a) {
    ll m = (x + y) / 2;
    int id1 = upper_bound(a.begin(), a.end(), m) - a.begin();
    int id2 = id1 - 1;
    if ((id1 >= 0) && (id1 < a.size())) {
        res = min(res, comp(x, y, a[id1]));
    }
    if ((id2 >= 0) && (id2 < a.size())) {
        res = min(res, comp(x, y, a[id2]));
    }
}

void solve() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        vector<ll> a(n1), b(n2), c(n3);
        for (int i = 0; i < n1; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n2; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n3; ++i) {
            cin >> c[i];
        }
        res = comp(a[0], b[0], c[0]);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        for (int i = 0; i < n1; ++i) {
            ll x = a[i];
            int id1 = upper_bound(b.begin(), b.end(), x) - b.begin();
            int id2 = id1 - 1;
            if ((id1 >= 0) && (id1 < b.size())) {
                comp(x, b[id1], c);
            }
            if ((id2 >= 0) && (id2 < b.size())) {
                comp(x, b[id2], c);
            }
            id1 = upper_bound(c.begin(), c.end(), x) - c.begin();
            id2 = id1 - 1;
            if ((id1 >= 0) && (id1 < c.size())) {
                comp(x, c[id1], b);
            }
            if ((id2 >= 0) && (id2 < c.size())) {
                comp(x, c[id2], b);
            }
        }
        cout << res << "\n";
    }

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