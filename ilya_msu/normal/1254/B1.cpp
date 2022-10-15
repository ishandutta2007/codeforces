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
const ll N = 100000 + 10;

void solve() {
    ll n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        if(a[i])
            b.push_back(i);
    }
    int m = b.size();
    if (m <= 1) {
        cout << -1 << "\n";
        return;
    }
    vector<ll> al;
    for (ll d = 2; d <= m; ++d) {
        if (m % d == 0) {
            al.push_back(d);
        }
    }
    ll res = n * n;
    for (int ii = 0; ii < al.size(); ++ii) {
        int k = al[ii];
        ll cur = 0;
        int q = m / k;
        for (int i = 0; i < q; ++i) {
            int st = i * k, en = i * k + k;
            int mid = (st + en) / 2;
            for (int j = st; j < en; ++j) {
                cur += abs(b[mid] - b[j]);
            }
        }
        res = min(res, cur);
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