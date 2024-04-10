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


void solve() {
    ll n, u;
    cin >> n >> u;
    vector<ll> e(n);
    for (int i = 0; i < n; ++i)
        cin >> e[i];
    //sort(e.begin(), e.end());
    double res = 0;
    bool z = 1;
    for (int i = 0; i < n; ++i) {
        ll up = u + e[i];
        int id = upper_bound(e.begin(), e.end(), up) - e.begin() - 1;
        if (id > i + 1) {
            z = 0;
            res = max(res, (e[id] - e[i + 1]) * 1.0 / (e[id] - e[i]));
        }
    }
    if (z)
        cout << -1 << endl;
    else
        printf("%0.18f\n", res);
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