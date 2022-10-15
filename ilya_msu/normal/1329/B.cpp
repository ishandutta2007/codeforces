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


void solve(int d, int m) {
    int sz = 0;
    int dd = d;
    while (dd > 0) {
        dd /= 2;
        ++sz;
    }
    ll res = 1;
    ll x = 1;
    for (int i = 1; i < sz; ++i) {
        res = (res * (x + 1)) % m;
        x *= 2;
    }
    res = (res * (d - x + 2)) % m;
    res = (res + m - 1) % m;
    cout << res << "\n";
}

void solve() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int d, m;
        cin >> d >> m;
        solve(d, m);
    }
    return;
    

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