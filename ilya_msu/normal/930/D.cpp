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
//#include<unordered_map>




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
const int negINF = numeric_limits<int>::min();

const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

ll get(vector<pll> p) {
    if (p.empty())
        return 0;
    sort(p.begin(), p.end());
    int n = p.size();
    ll res = 0;
    vector<ll> prMax(n, negINF), prMin(n, INF), sufMax(n, negINF), sufMin(n, INF);
    prMax[0] = p[0].second;
    prMin[0] = p[0].second;
    sufMax[n - 1] = p[n - 1].second;
    sufMin[n - 1] = p[n - 1].second;
    for (int i = 1; i < n; ++i) {
        prMax[i] = max(prMax[i - 1], p[i].second);
        prMin[i] = min(prMin[i - 1], p[i].second);
    }
    for (int i = n - 2; i >= 0; --i) {
        sufMax[i] = max(sufMax[i + 1], p[i].second);
        sufMin[i] = min(sufMin[i + 1], p[i].second);
    }
    for (int i = 1; i < n; ++i) {
        res += ((p[i].first - p[i - 1].first) * max((ll)(0), min(prMax[i - 1], sufMax[i]) - max(prMin[i - 1], sufMin[i]))) / 4;
    }
    /*int l = 0;
    while (l < n) {
        int r = l;
        while ((r < n) && (p[r].first == p[l].first))
            ++r;
        if ((l > 0) && (r < n))
            res += max((ll)(0), min(prMax[l - 1], sufMax[r]) - max(prMin[l - 1], sufMin[r])) / 2;
        l = r;
    }*/
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<pll> p1, p2;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int s = x + y, d = x - y;
        if (abs(s) & 1)
            p2.emplace_back(s, d);
        else
            p1.emplace_back(s, d);
    }
    cout << get(p1) + get(p2) << endl;
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