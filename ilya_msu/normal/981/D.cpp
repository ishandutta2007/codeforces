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
const long double eps = 1e-8;
const int INF = numeric_limits<int>::max();
const int negINF = numeric_limits<int>::min();

const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

int n, k;
vector<ll> a;
vector<vector<ll> > sum;

bool ok(ll x) {
    vector<int> d(n + 1, 0);
    d[0] = 1;
    for (int it = 0; it < k; ++it) {
        for (int j = n; j >= 0; --j) {
            if (d[j] == 0)
                continue;
            for (int pos = j + 1; pos <= n; ++pos) {
                if ((sum[j][pos] & x) == x)
                    d[pos] = 1;
            }
            d[j] = 0;
        }
    }
    return d[n];
}


void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sum.assign(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            sum[i][j] = sum[i][j - 1] + a[j - 1];
        }
    }
    ll x = 0;
    for (int i = 56; i >= 0; --i) {
        ll y = x + (1LL << i);
        if (ok(y))
            x = y;
    }
    cout << x << endl;
    return;
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