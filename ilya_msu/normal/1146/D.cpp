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

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    ll m, a, b;
    cin >> m >> a >> b;
    vector<int> d(a, -1);
    d[0] = 0;
    int x = 0;
    int mx = 0;
    ll dd = gcd(a, b);
    while (true) {
        x += a;
        mx = max(x, mx);
        while (x > b) {
            x -= b;
            d[x] = mx;
        }
        if (x == b)
            break;
    }
    ll q = m / dd;
    ll res = (q + 1) * (m + 1) - q * (q + 1) / 2 * dd;
    for (int i = 0; i < min(a, m + 1); ++i) {
        if (d[i] == -1) {
            continue;
        }
        res -= m - i + 1;
        res += max((ll)0, m - d[i] + 1);
    }
    for (int i = a; i < min(a + b + 10, m + 1); ++i) {
        int j = i % a;
        if (d[j] == -1) {
            continue;
        }
        res -= m - i + 1;
        res += max((ll)0, m - max(i, d[j]) + 1);
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
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}