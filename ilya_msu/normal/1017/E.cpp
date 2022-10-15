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

bool clockwise(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

bool counterClockwise(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) > 0;
}

vector<pii> convexHull(vector<pii> a) {
    if (a.size() < 3)
        return a;
    sort(a.begin(), a.end());
    pii p1 = a[0], p2 = a.back();
    vector<pii> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < a.size(); ++i) {
        if ((i == a.size() - 1) || clockwise(p1, a[i], p2)) {
            while ((up.size() >= 2) && (!clockwise(up[up.size() - 2], up[up.size() - 1], a[i])))
                up.pop_back();
            up.push_back(a[i]);
        }
        if ((i == a.size() - 1) || (counterClockwise(p1, a[i], p2))) {
            while ((down.size() >= 2) && (!counterClockwise(down[down.size() - 2], down[down.size() - 1], a[i])))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (int i = 0; i < up.size(); ++i)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; --i)
        a.push_back(down[i]);
    return a;
}


vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while ((i + z[i] < n) && (s[z[i]] == s[i + z[i]]))
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

ll norm2(const pii& p) {
    return (ll)(p.first) * (p.first) + (ll)(p.second) * p.second;
}

ll gcd(ll x, ll y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

string get(vector<pii>& a) {
    int n = a.size();
    vector<pii> v(n);
    a.push_back(a[0]);
    for (int i = 0; i < n; ++i) {
        v[i].first = a[i + 1].first - a[i].first;
        v[i].second = a[i + 1].second - a[i].second;
    }
    string s = "";
    v.push_back(v[0]);
    for (int i = 0; i < n; ++i) {
        s += to_string((norm2(v[i]))) + '!';
        //ll x = (ll)v[i].first * v[i + 1].second - (ll)(v[i].second) * v[i + 1].first;
        ll y = (ll)v[i].first * v[i + 1].first + (ll)(v[i].second) * v[i + 1].second;
        /*
        ll d = gcd(abs(x), abs(y));
        x /= d, y /= d;
        if (x < 0) {
            x = -x;
            y = -y;
        }
        if ((x == 0) && (y < 0)) {
            x = -x;
            y = -y;
        }
        s += to_string(x) + ',' + to_string(y) + '$';*/
        s += to_string(y) + '$';

    }
    return s;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
    }
    a = convexHull(a), b = convexHull(b);
    if (a.size() != b.size()) {
        cout << "NO\n";
        return;
    }
    string s1 = get(a), s2 = get(b);
    int sz = s1.size();
    if (s2.size() != sz) {
        cout << "NO\n";
        return;
    }
    string s = s1 + "#" + s2 + s2;
    //if (s.size() > 1000000)
    //    cerr << s.size() << "\n";
    vector<int> res = z_function(s);
    for (int i = 1; i < res.size(); ++i) {
        if (res[i] >= sz) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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