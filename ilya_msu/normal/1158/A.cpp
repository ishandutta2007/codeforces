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
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    ll m, n;
    cin >> m >> n;
    vector<ll> a(m), b(n);
    for (int i = 0; i < m; ++i) 
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    ll res = 0;
    ll M = 0, M2 = 0;
    for (int i = 0; i < m; ++i) {
        res += n * a[i];
        if (a[i] > M) {
            M2 = M;
            M = a[i];
        }
        else {
            if (a[i] > M2) {
                M2 = a[i];
            }
        }
    }
    ll add = 0;
    bool eq = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] < M) {
            cout << -1 << endl;
            return;
        }
        add += b[i] - M;
        if (M == b[i])
            eq = 1;
    }
    if (eq)
        cout << res + add << endl;
    else {
        cout << res + add + M - M2 << endl;

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