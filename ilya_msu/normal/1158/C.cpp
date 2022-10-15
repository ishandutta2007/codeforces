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

vector<int> a, p;
int ok;

void solve(int l, int r, int add) {
    if (l == r)
        return;
    vector<int> b;
    int x = l;
    while (x < r) {
        b.push_back(x);
        x = a[x];
    }
    if (x > r) {
        ok = 0;
        return;
    }
    b.push_back(r);
    for (int i = 0; i + 1 < b.size(); ++i) {
        p[b[i]] = add + r - l + i - b.size() + 1;
    }
    int y = 0;
    for (int i = 0; i + 1 < b.size(); ++i) {
        solve(b[i] + 1, b[i + 1], add + y);
        y += b[i + 1] - b[i] - 1;
    }
    return;

}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    ok = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        if (a[i] == -2) {
            a[i] = i + 1;
        }
    }
    p.assign(n + 1, -1);
    solve(0, n, 1);
    if (!ok) {
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] <<  " ";
    }
    cout << "\n";

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
    for (int i = 0; i < t; ++i) {
        solve();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}