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
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second)
            swap(a[i].first, a[i].second);
    }
    ll res = 0;
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        b.push_back(a[i].first);
        if (a[i].second != a[i].first)
        b.push_back(a[i].second);
    }
    sort(b.begin(), b.end());
    ll k = 1;
    for (int i = 1; i < b.size(); ++i) {
        if (b[i] == b[i - 1]) {
            ++k;
        }
        else {
            res += k * (k - 1) / 2;
            k = 1;
        }
    }
    res += k * (k - 1) / 2;
    sort(a.begin(), a.end());
    k = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++k;
        }
        else {
            if (a[i - 1].first != a[i - 1].second) {
                res -= k * (k - 1) / 2;
            }
            k = 1;
        }
    }
    if (a[n - 1].first != a[n - 1].second) {
        res -= k * (k - 1) / 2;
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
/*for (int i = 1; i < 1000; ++i) {
    cout << i << ": ";
    string s = to_string(i);
    solve(s);
}*/
solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}