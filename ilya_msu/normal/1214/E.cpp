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
#include <random>
#include <chrono>


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


void solve() {
    int n;
    cin >> n;
    vector<pii> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i].first;
        d[i].second = 2 * i + 1;
    }
    sort(d.rbegin(), d.rend());
    for (int i = 0; i < n - 1; ++i) {
        cout << d[i].second << " " << d[i + 1].second << "\n";
    }
    vector<int> a(2 * n, -1);
    for (int i = 0; i < n; ++i)
        a[i] = d[i].second;
    for (int i = 0; i < n; ++i) {
        int x = d[i].first;
        int v = d[i].second + 1;
        int p = i + x;
        if (a[p - 1] == -1) {
            assert(0);
            return;
        }
        if (a[p] == -1)
            a[p] = v;
        cout << a[p - 1] << " " << v << "\n";
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