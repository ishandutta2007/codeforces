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
#include<unordered_set>




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
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vector<int> c1, c2;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += b[i];
        if (a[i])
            c1.push_back(b[i]);
        else
            c2.push_back(b[i]);
    }
    sort(c1.rbegin(), c1.rend());
    sort(c2.rbegin(), c2.rend());
    ll add1 = 0, add2 = 0;
    int sz1 = c1.size(), sz2 = c2.size();
    if ((sz1 == 0) || (sz2 == 0)) {
        cout << res << "\n";
        return;
    }
    if (sz1 == sz2) {
        res = res * 2 - min(c1[sz1 - 1], c2[sz2 - 1]);
        cout << res << "\n";
        return;
    }
    int m = min(sz1, sz2);
    for (int i = 0; i < m; ++i) {
        res += c1[i] + c2[i];
    }
    cout << res << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}