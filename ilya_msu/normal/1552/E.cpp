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


void solve() {
    int n, k;
    cin >> n >> k;
    int u = (n + k - 2) / (k - 1);
    vector<vector<int> > p(n);
    vector<pii> res(n);
    vector<int> used(n, 0);
    int t = 2;
    int cc = 0;
    for (int i = 0; i < n * k; ++i) {
        int x;
        cin >> x;
        --x;
        p[x].push_back(i);
        if (used[x])
            continue;
        if (p[x].size() == t) {
            ++cc;
            res[x] = pii(p[x][t - 2], p[x][t - 1]);
            used[x] = 1;
        }
        if (cc == u) {
            ++t;
            cc = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i].first + 1 << " " << res[i].second + 1 << "\n";
    }
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i)
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}