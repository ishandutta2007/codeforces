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
const ll mod = 998244353;
const ll N = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;

void solveCase() {
    int n;
    cin >> n;
    int s = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s ^= a[i];
    }
    if (s == 0) {
        cout << "DRAW\n";
        return;
    }
    int j = 0;
    while (s > 0) {
        s /= 2;
        ++j;
    }
    --j;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] & (1 << j)) {
            ++x;
        }
    }
    if ((x % 4) == 1) {
        cout << "WIN\n";
        return;
    }
    int y = n - x;
    if (y & 1) {
        cout << "WIN\n";
    }
    else {
        cout << "LOSE\n";
    }
}

void solve() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solveCase();
    }

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