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
#include<iterator>
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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;

int inter(pii a, pii b) {
    if (a.first > a.second) swap(a.first, a.second);
    if (b.first > b.second) swap(b.first, b.second);
    if (a.first > b.first) swap(a, b);
    if (a.second < b.first) return 0;
    if (a.second > b.second) return 0;
    return 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int res = 0;
    vector<int> p(2 * n, -1);
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        p[x] = y;
        p[y] = x;
    }
    vector<int> fr;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == -1) {
            fr.push_back(i);
        }
    }
    for (int i = 0; i < n - k; ++i) {
        p[fr[i]] = fr[i + n - k];
        p[fr[i + n - k]] = fr[i];
    }
    vector<pii> h;
    for (int i = 0; i < 2 * n; ++i) {
        if (i < p[i])
            h.push_back(make_pair(i, p[i]));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            res += inter(h[i], h[j]);
        }
    }
    cout << res << endl;
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}